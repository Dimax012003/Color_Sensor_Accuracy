import serial
import pandas as pd
from Receiver import receiver
from RGB import transceiver
seria=serial.Serial(port='COM4',baudrate=9600)
rgb_data=pd.DataFrame(columns=['First','Second','Third'])
receiver_data=pd.DataFrame(columns=['First','Second','Third'])
while True:

    ser=seria.readline(1000)
    serstr=str(ser,'UTF-8')

    color_list=serstr.split(' ')

    Receive=receiver(color_list[3:6])
    Rgb=transceiver(color_list[0:3])

    rgb_data.loc[len(rgb_data.index)]=Rgb.sort_colors()
    rgb_data.to_csv('rgb_data.csv')
    receiver_data.loc[len(receiver_data.index)] = Receive.sort_colors()
    receiver_data.to_csv('receiver_data.csv')



