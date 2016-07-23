# -*- coding: utf-8 -*-
"""
Created on Fri Jul 22 11:35:51 2016

@author: ..::/Rad!n\::..
"""

import json
import requests as r
import time
import random

uid=input("enter uid : ")
temp_m=int(input("enter reference temperature : "))
hum_m=int(input("enter reference humidity : "))
pulse_m=int(input("enter reference pulse : "))
inter=input("enter post interval : ")
while (True):
    temp=int(temp_m)
    hum=int(hum_m)
    pulse=int(pulse_m)
    temp=temp+random.randint(-1*temp,temp)*0.05
    hum=hum+random.randint(-1*hum,hum)*0.05
    pulse=pulse+random.randint(-1*pulse,pulse)*0.15
    print(temp,hum,pulse)
    data = {"reqtype":"upload","uid":str(uid),"password":"123","temperature":str(temp),"humidity":hum,"pulse":str(pulse),"reqtime":""}
    data_json = json.dumps(data)
    req = r.post('http://autiot.coolpage.biz/users.php',data_json)
    print("sent")
    # print(req.text)
    time.sleep(int(inter))

