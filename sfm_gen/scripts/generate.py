import os
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-l', type=str, default='6222720')
    parser.add_argument('-msg', type=str, default='sensor_msgs/msg/Image.msg')

    

    args = parser.parse_args()
    with open('./example.sh', 'w') as f:
        f.write('#!/bin/sh\n')
        f.write('\n')

        f.write('ROS_PATH=/opt/ros/noetic/share\n')
        f.write('\n')

        f.write('python3 gen_header.py ${ROS_PATH}/' + args.msg + ' \\' + '\n')
        f.write('  -Istd_msgs:${ROS_PATH}/std_msgs/msg \\' + '\n')
        f.write('  -p sensor_msgs -o ../include -e ../templates/\n')
    
    # filename = '../include/' + args.msg.split('/')[-1].split('.')[0] + '.h' 
    max_len_str = args.l

    filelines = []
    with open('../templates/raw.h.template', 'r') as f:
        filelines = f.readlines()
    filelines[92] = filelines[92].replace('MAX_LEN', max_len_str)
    
    with open('../templates/msg.h.template', 'w') as f:
        for line in filelines:
            f.write(line)

    os.system('./example.sh')

