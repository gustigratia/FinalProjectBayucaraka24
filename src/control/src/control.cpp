#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/header.hpp"
#include <chrono>
#include "griddata/msg/game_state.hpp"

using namespace std::chrono_literals;

// Create Node
class MyNode : public rclcpp::Node {
    public:
        MyNode() : Node("pubcontrol"){
            // Subscribe vision topic
            subscription_ = this->create_subscription<griddata::msg::GameState>("vision",10, 
            std::bind(&MyNode::timer_callback, this, std::placeholders::_1));
            // Publish control topic
            publisher_ = this->create_publisher<griddata::msg::GameState>("control", 10);
            //periodic timer
            timer_ = this->create_wall_timer(50000ms, std::bind(&MyNode::publish_msg, this));
            
        }

    private:
        // Data members
        int cell[9];
        int turn;

        // Method to check the game status
        bool GameOver(int board[]) {
            // Check for a win
            if ((board[0] != 0 && board[0] == board[1] && board[1] == board[2]) ||
                (board[3] != 0 && board[3] == board[4] && board[4] == board[5]) ||
                (board[6] != 0 && board[6] == board[7] && board[7] == board[8]) ||
                (board[0] != 0 && board[0] == board[3] && board[3] == board[6]) ||
                (board[1] != 0 && board[1] == board[4] && board[4] == board[7]) ||
                (board[2] != 0 && board[2] == board[5] && board[5] == board[8]) ||
                (board[0] != 0 && board[0] == board[4] && board[4] == board[8]) ||
                (board[2] != 0 && board[2] == board[4] && board[4] == board[6])) {
                return true; // Someone won
            }

            // Check for a tie
            for (int i = 0; i < 9; ++i) {
                if (board[i] == 0) return false; // Found an empty cell, game is not over yet
            }
            return true; // Board is full, it's a tie
        }

        // Evaluate the game 
        int evaluate(int arr[9]){
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
        
        // Minimax algorithm for tic-tac-toe
        int minimax(int data[], int depth, bool isMaximize){
            if (GameOver(data) || depth == 5){
                return evaluate(data);
            }
            else {
                // maximizing player
                if(isMaximize){
                    int maxEval = std::numeric_limits<int>::min();
                    for(int i = 0;i<9;++i){
                        if(data[i] == 0){
                            data[i] = 2;
                            // Recursive
                            int eval = minimax(data, depth+1, false);
                            data[i] = 0;
                            maxEval = std::max(maxEval, eval);  
                        }
                    }
                    return maxEval;
                }
                // Minimizing bot
                else{
                    int minEval = std::numeric_limits<int>::max();
                    for(int i = 0;i<9;++i){
                        if(data[i] == 0){
                            data[i] = 1;
                            // Recursive
                            int eval = minimax(data, depth+1, true);
                            data[i] = 0;
                            minEval = std::min(minEval, eval);
                        }
                    }
                    return minEval;
                }
            }
                
        }

        // Subscription callback
        void timer_callback(const griddata::msg::GameState::SharedPtr msg){
            // seubscribe message and store it into the data member
            for(int i =0 ;i<9;++i){
                cell[i] = msg->cell[i];
            }

            // Initiate Minimax Algorithm
            int bestmove = -1;
            int besteval = std::numeric_limits<int>::min();
            for(int i = 0;i<9;++i){
                if(cell[i] == 0){
                    cell[i] = 2;
                    int eval = minimax(cell, 0, false);
                    cell[i] = 0;
                    if(eval>besteval){
                        besteval = eval;
                        bestmove = i;
                    }
                }
            }
            // if the game is not over yet, continue to proceed
            if(msg->over){
                if(msg->gameturn % 2 == 0){
                    cell[bestmove] = 2;
                }
            }
        }
        
        // Publishing
        void publish_msg(){
            auto msg = griddata::msg::GameState();
            for(int i = 0;i<9;i++){
                msg.cell[i] = cell[i];
            }
            publisher_->publish(msg);
            
        }
        
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Subscription<griddata::msg::GameState>::SharedPtr subscription_;
        rclcpp::Publisher<griddata::msg::GameState>::SharedPtr publisher_;


    
};

// Spin Node
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}