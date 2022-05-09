# PlusPlus
A medium-hard reversing challenge I created for the finals of the Danish Cyberchampionship.
Description:
```
Hey, I found this cool programming language that is way better than C. I love these STL containers. Find the flag that makes the binary print "You win!".
```

Download [plusplus.zip](plusplus.zip) to try the challenge.

Check out [main.cpp](main.cpp) and [solve.py](solve.py) to understand the solution.
Compiled with:
```bash
g++ main.cpp -s -o plusplus
```

## Idea
<details>
  <summary>Spoiler warning</summary>
  
  The idea was to create a C++ challenge that utilizes classes and (to a lesser extent) STL datastructures, so it becomes harder to understand the decompilation. I also added a member variable to the Encryptor class that tracks the result of the last computation and uses it in the next, making reversing the process a bit trickier.
  
</details>