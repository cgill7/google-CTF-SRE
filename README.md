# Google CTF reverse engineering solution using Ghidra and ANGR + Claripy

After failing with basic `file` `strings` `grep` and `ltrace` commands on terminal

Firstly, we will use Ghidra to analyze the source code of the "a.out" executable.


1. Install Ghidra from the NSA's website : https://ghidra-sre.org/
  <br /> (make sure you have a JDK installed to run Ghidra)
  <br /> #Radare2 can also be used


2. Source code is extraced by disassembling using Ghidra. (main.c) <br />


3. Analyze 
   <br /> i. The assembly code to view the addresses of "SUCCESS" and "FAILURE" prompts
   <br /> ii. We also see that that is flag variable has 16 bytes allocated and thus it would be 15 characters in legnth (last byte for NULL)
  

4. We will now use ANGR and write a python script. (flagfinder.py)
 
 
5. After running the script we get the flag ie. CTF{S1MDf0rM3!}


### References used <br />
 https://docs.angr.io/
<br /> https://osandamalith.com/2019/02/11/linux-reverse-engineering-ctfs-for-beginners/
<br /> https://github.com/Dvd848
<br /> https://www.youtube.com/watch?v=75gBFiFtAb8



