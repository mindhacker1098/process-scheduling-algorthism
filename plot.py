import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
data = pd.read_csv("ducky.csv")
w=0.4
x=data['name']
y=data["turn around"]
z=data["waiting time"]
first=np.arange(len(x))
second=[i+w for i in first]
plt.bar(first,y,w,label="turn around time")
plt.bar(second,z,w,label="waiting time")
if len(x)==4:
    plt.xlabel("name")

else:
    plt.xlabel("time quantum")
plt.ylabel("time")
plt.title("comparision")
plt.xticks(first+w/2,x)
plt.legend()
plt.show()
