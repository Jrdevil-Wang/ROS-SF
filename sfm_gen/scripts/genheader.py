import genmsg.msgs
import gencpp

MSG_TYPE_TO_CPP = {
  'byte': 'int8_t',
  'char': 'uint8_t',
  'bool': 'uint8_t',
  'uint8': 'uint8_t',
  'int8': 'int8_t',
  'uint16': 'uint16_t',
  'int16': 'int16_t',
  'uint32': 'uint32_t',
  'int32': 'int32_t',
  'uint64': 'uint64_t',
   'int64': 'int64_t',
  'float32': 'float',
  'float64': 'double',
  'string': 'std::string',
  'time': 'ros::Time',
  'duration': 'ros::Duration'
}

def is_fixed_length(type, package, msg_context, search_path):
  if (type == 'string'):
    return False
  if (genmsg.msgs.is_builtin(type)):
    return True
  (base_type, is_array, array_len) = genmsg.msgs.parse_type(type)
  if (not is_array):
    rtype = genmsg.msgs.resolve_type(type, package)
    spec = genmsg.msg_loader.load_msg_by_type(msg_context, rtype, search_path)
    return gencpp.is_fixed_length(spec, msg_context, search_path)
  if (not array_len is None):
    return False
  return is_fixed_length(base_type, package, msg_context, search_path)

def msg_type_to_cpp(type, package, msg_context, search_path):
  (base_type, is_array, array_len) = genmsg.msgs.parse_type(type)
  cpp_type = None
  is_builtin = genmsg.msgs.is_builtin(base_type)
  if (is_builtin):
    cpp_type = MSG_TYPE_TO_CPP[base_type]
  elif (len(base_type.split('/')) == 1):
    if (genmsg.msgs.is_header_type(base_type)):
      cpp_type = 'Header'
    else:
      cpp_type = '%s'%(base_type)
  else:
    pkg = base_type.split('/')[0]
    msg = base_type.split('/')[1]
    if (pkg == 'std_msgs' and msg == 'Header'):
      cpp_type = 'Header'
    elif (not is_fixed_length(base_type, package, msg_context, search_path)):
      cpp_type = '%s'%(msg)
    else:
      cpp_type = '::%s::%s'%(pkg, msg)
  if (not is_array):
    if (base_type == 'string'):
      return 'String_vec'
    else :
      return cpp_type
  if (not array_len is None):
    return 'boost::array< %s, %s >'%(cpp_type, array_len)
  return 'Vec< %s >'%(cpp_type)
