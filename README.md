LiquiNet is a program that can solve complex Water, or any other Liquid, Pipe Network problems easily. Based on Paper published by Anthony G. Collins in May 1973, it applies Finite Element Method.  
  
# How to use, with Example.  
  
We will start with the diagram given in the Documentation.  
  
![alt tag](https://github.com/samadritakarmakar/LiquiNet/blob/master/Documentation/Problem%20Set.png)
  
The numbers within the circles indicate the node numbers. The numbers within the squares indicate the element numbers.  

The Program by default is independent of the type of Unit system used. But the default values shown at the start of the program are in SI units. Hence, if you wants to use units of his choice, suppose the FPS system, then you must take care of that the input values are in correct FPS values.  
In SI system, the gravitational acceleration is in m2/s, density is in kg/m3, Dynamic Viscosity is in Ns/m2, Flow Rate is in m3/s, Internal Diameter, Roughness, Length, Booster, Head, Head Loss is in meter.  

So, there are 3 elements and 3 nodes. We shall enter the same in the 'Initialize' window.  
  
![alt tag](https://github.com/samadritakarmakar/LiquiNet/blob/master/Documentation/Initialize.png)
  
Suppose the Problem is such that,  
Head at Node 1 is 0 meter  
Flow out at Node 2 is -0.045m3/s (Negetive because it is flowing out of the system)  
Flow out at Node 3 is -0.035m3/s  
Diameter throughout is 0.243m  

Then click the 'Go to Detail Input' button  
  
A new window will pop-up.  
'Element Number' is filled automatically and cannot be edited.  
Enter,  
'Flow is from' 'Node' 1 'to' 'Node' 2  
![alt tag](https://github.com/samadritakarmakar/LiquiNet/blob/master/Documentation/Input_Details.png)
  
Select the 'Booster' radio button
