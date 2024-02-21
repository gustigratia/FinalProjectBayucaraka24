#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/header.hpp"
#include <chrono>
#include "griddata/msg/game_state.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node {
    public:
        MinimalPublisher() : Node("pubcontrol"){
            // subscribing
            subscription_ = this->create_subscription<griddata::msg::GameState>("vision",10, 
            std::bind(&MinimalPublisher::timer_callback, this, std::placeholders::_1));
            // publishing
            publisher_ = this->create_publisher<griddata::msg::GameState>("control", 10);
            //periodic timer
            timer_ = this->create_wall_timer(100ms, std::bind(&MinimalPublisher::publish_msg, this));
            
        }

    private:
        int cell[9] = {0,0,0,0,0,0,0,0,0};
        int turn = 0;
        
        int check(int arr[9]){
            const int win_pattern[8][3] = {
                {0,1,2}, {3,4,5}, {6,7,8},
                {0,3,6}, {1,4,7}, {2,5,8},
                {0,4,8},{2,4,6}
            };

            for(int i = 0;i<8;i++){
                int countplayer = 0;
                int countbot = 0;
                for(int j = 0;j<3;j++){
                    if(arr[win_pattern[i][j]]==1){
                        countplayer++;
                    }
                    else if(arr[win_pattern[i][j]]==2){
                        countbot++;
                    }
                }
                if(countplayer == 3){
                    return -10;
                }
                if(countbot == 3){
                    return 10;
                }
            }
            return 0;
        }

        bool GameOver(int data[]){
            return check(data) != 0;
        }

        int minimax(int data[], int depth, bool isMaximize, int alpha, int beta){
            if(GameOver(data)){
                return check(data);
            }
            if(isMaximize){
                int maxEval = -99999999;
                for(int i = 0;i<9;i++){
                    if(data[i] == 0){
                        data[i] = 2;
                        int eval = minimax(data, depth+1, false, alpha, beta);
                        data[i] = 0;
                        maxEval = std::max(maxEval, eval);
                        alpha = std::max(alpha, eval);
                        if (beta<=alpha){
                            break;
                        }
                    }
                }
                return maxEval;
            }
            else{
                int minEval = 99999999;
                for(int i = 0;i<9;i++){
                    if(data[i] == 0){
                        data[i] = 1;
                        int eval = minimax(data, depth+1, true, alpha, beta);
                        data[i] = 0;
                        minEval = std::min(minEval, eval);
                        alpha = std::min(alpha, eval);
                        if (beta<=alpha){
                            break;
                        }
                    }
                }
                return minEval;
            }
        }

        void botmove(){
            int bestmove = -1;
            int bestEval = -99999999;
            for(int i = 0;i<9;i++){
                if(MinimalPublisher::cell[i] == 0){
                    MinimalPublisher::cell[i] = 2;
                    int eval = minimax(cell, 0, false, -99999999, 99999999);
                    MinimalPublisher::cell[i] = 0;
                    if(eval>bestEval){
                        bestEval = eval;
                        bestmove = i;
                    }
                }
            }
            MinimalPublisher::cell[bestmove] = 2;
        }



        void timer_callback(griddata::msg::GameState::SharedPtr msg){
            // Tic Tac Toe Algorithm
            for(int i = 0;i<9;i++){
                if(msg->cell[i] == 1){
                    cell[i] = 1;
                    
                }
                if(msg->cell[i] == 2){
                    cell[i] = 2;
                    
                }
            }
            // turn = msg->game_turn;
            if(turn%2 == 1){
                botmove();
            }

            
        

            RCLCPP_INFO(this->get_logger(), "Publishing %d", cell[5]);
        }
        
        void publish_msg(){
            auto msg = griddata::msg::GameState();
            for(int i = 0;i<9;i++){
                msg.cell[i] = cell[i];
            }
            // msg.game_turn = turn;

            // msg.cell1 = cell[0];
            // msg.cell2 = cell[1];
            // msg.cell3 = cell[2];
            // msg.cell4 = cell[3];
            // msg.cell5 = cell[4];
            // msg.cell6 = cell[5];
            // msg.cell7 = cell[6];
            // msg.cell8 = cell[7];
            // msg.cell9 = cell[8];
            RCLCPP_INFO(this->get_logger(), "Publishing %d", msg.cell[5]);
            publisher_->publish(msg);
        }
        
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Subscription<griddata::msg::GameState>::SharedPtr subscription_;
        rclcpp::Publisher<griddata::msg::GameState>::SharedPtr publisher_;


    
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MinimalPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}