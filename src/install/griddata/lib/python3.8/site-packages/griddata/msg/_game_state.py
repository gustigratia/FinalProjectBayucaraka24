# generated from rosidl_generator_py/resource/_idl.py.em
# with input from griddata:msg/GameState.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'cell'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GameState(type):
    """Metaclass of message 'GameState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('griddata')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'griddata.msg.GameState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__game_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__game_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__game_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__game_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__game_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GameState(metaclass=Metaclass_GameState):
    """Message class 'GameState'."""

    __slots__ = [
        '_cell',
        '_gameturn',
        '_over',
    ]

    _fields_and_field_types = {
        'cell': 'int8[9]',
        'gameturn': 'int64',
        'over': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 9),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'cell' not in kwargs:
            self.cell = numpy.zeros(9, dtype=numpy.int8)
        else:
            self.cell = numpy.array(kwargs.get('cell'), dtype=numpy.int8)
            assert self.cell.shape == (9, )
        self.gameturn = kwargs.get('gameturn', int())
        self.over = kwargs.get('over', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if all(self.cell != other.cell):
            return False
        if self.gameturn != other.gameturn:
            return False
        if self.over != other.over:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def cell(self):
        """Message field 'cell'."""
        return self._cell

    @cell.setter
    def cell(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'cell' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 9, \
                "The 'cell' numpy.ndarray() must have a size of 9"
            self._cell = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 9 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'cell' field must be a set or sequence with length 9 and each value of type 'int' and each integer in [-128, 127]"
        self._cell = numpy.array(value, dtype=numpy.int8)

    @property
    def gameturn(self):
        """Message field 'gameturn'."""
        return self._gameturn

    @gameturn.setter
    def gameturn(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gameturn' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'gameturn' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._gameturn = value

    @property
    def over(self):
        """Message field 'over'."""
        return self._over

    @over.setter
    def over(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'over' field must be of type 'bool'"
        self._over = value
