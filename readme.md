My friend made a game about eating balls in python/pygame so I decided to spend the first half of my Sunday making a clone but in C++ / SFML so that I could get better at C++ and SFML and eating balls.


## Controls

1. W/D or arrow keys to move.

2. Esc / cross button / alt + f4 / power off button to quit

## System Requirments

**Required**
1. linux or Win32
2. GCC or MinGW  *
3. Cmake *
4. Make *

*If you want to build from source code. Check releases for the exe.

## Build Instructions
**Win32**

Open powershell and enter the following commands
``` 
git clone https://github.com/oh-facts/eat-my-balls.git
```

Navigate inside the folder to the root directory (the one with the src files/vendor/res) and open powershell there

Now do
```
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make all
./Game
```

**Linux**

Open Console and enter the following commands
``` 
git clone https://github.com/oh-facts/eat-my-balls.git
cd eat-my-balls
mkdir build
cd build
cmake .. -G "Unix Makefiles"
make all
./Game
```

and you should be eating balls.



If there are any errors, please stop making them.


cheers,

facts

