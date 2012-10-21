# Yet another Turing machine

Building:
```
$ make
```

## Command-line arguments
Program has the following arguments syntax:
```
PATH_TO_ACTION_TABLE_FILE STATE OFFSET ITERATIONS_COUNT [INITIAL_TAPE_CONTENT]
```
You may use ```.``` (dot) for defining spaces for tape.

## Examples
Runs rotating animation:
```
$ bin/turing_machine tables/animation 0 0 100
```

Runs copying algorithm:
```
$ bin/turing_machine tables/copying 0 10 100 .IIII
```

Runs conjunction of binary numbers:
```
$ bin/turing_machine tables/conjunction 0 10 200 .1100.1010
```
