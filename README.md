# Yet another turing machine

Compiles using GCC:
```
>make
```

## Command-line arguments
Program has the following arguments syntax:
```
PATH_TO_ACTION_TABLE_FILE STATE OFFSET ITERATIONS_COUNT [INITIAL_TAPE_CONTENT]
```

## Examples
Runs rotating animation:
```
>bin\turing_machine tables\animation 0 0 100
```

Runs copying algorithm:
```
>bin\turing_machine tables\copying 0 10 100 $IIII
```