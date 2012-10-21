# Yet another Turing machine

Building:
```
$ make
```

## Command-line arguments
Program has the following arguments syntax:
```
turing_machine -f ACTION_TABLE_FILE -n ITERATIONS_COUNT [OPTIONS]
```
Where options are:
* ```-f``` Path to action table file.
* ```-n``` How much cycles will machine do.
* ```-o``` Start tape offset. 0 (zero) by default.
* ```-s``` Initial state. 0 (zero) by default.
* ```-t``` Initial tape content. Use . (dot) for spaces. Tape will be read from stdin if not specified.
* ```-v``` Verbose mode.

## Examples
Runs rotating animation:
```
$ bin/turing_machine -f tables/animation -n100 -t. -v
```

Runs copying algorithm:
```
$ bin/turing_machine -f tables/copying -n100 -o10 -t.IIII -v
```

Runs conjunction of binary numbers:
```
$ bin/turing_machine -f tables/conjunction -n200 -o10 -t.1100.1010 -v
```
