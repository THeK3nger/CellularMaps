# Cellular Map

### What is

Cellular Map is a simple implementation of a procedura map generator in C++. It uses the cellular automata technique in order to create structures similar to caves or natuaral environments.

## An Example

	##################################################
	####.....###...###...#############################
	###.......#...........#..#########################
	###.......................##################...###
	###........................################.....##
	####........................##############.......#
	#####.................#.....##############.......#
	######...............###....########..####......##
	######...............####..########.....##.....###
	######..............##############............####
	#######..###......################.............###
	#############.....#########..######............###
	#############.....#######.....######...........###
	##############...#######........####...##......###
	#############.....#####..........####..##.......##
	##########.......................####............#
	#########........................###.............#
	#########...........##............##............##
	########............##..........................##
	######..........................................##
	#####...........................................##
	#####..........................#.........####..###
	######........................###.......######..##
	#######.....................#####.......#####....#
	######......................####.........#.......#
	######...........................................#
	######..........##..................##...........#
	#####....#####..##.................###...........#
	###.....######...##...#............##...........##
	##......#####....########......................###
	#.......####......########..##..................##
	#........###......########..##...................#
	#........###......########.......................#
	##.........#.......######......#.................#
	##..........#......######.....###...............##
	#..........###.....######.....####..............##
	#..........##.......######.....###...............#
	##.........##........######.....###.....##.......#
	###...................#####......###...###......##
	####...................#####.....###....#.......##
	####....................######.................###
	###......................#####...............#####
	###................##....###......##........######
	##................###.............###......#######
	##...............####.............####....########
	###..............#####............######..########
	#######...#......########.........################
	############.....#########....#..#################
	##############..###########..#####################
	##################################################

## Usage

The usage for the class is shown in the example main provided in the source:

```cpp
int main() {
    // This is an use example for the CellularMap class.
    CellularMap cm(50, 50, 40);
    for (int i=0;i<4;++i){
        cm.evolveMap(CellularMap::CM_CONSERVATIVE);
    }
    for (int i=0;i<2;++i){
        cm.evolveMap(CellularMap::CM_SMOOTH);
    }
    string mapS = mapToString(cm);
    cout << mapS;
    cout << "........." << endl;
    return 0;
}
```

Easy. The result is stored in the class and can be accessed how shown in the print function.

```cpp
string mapToString(CellularMap& cm) {
    string returnString;
    for (int column = 0, row = 0; row < cm.getHeight(); row++) {
        for (column = 0; column < cm.getWidth(); column++)
        {
            returnString += cm.getElement(column, row) == 1 ? "#" : ".";
        }
        returnString += "\n";
    }
    return returnString;
}
```

More Easy.

### Dependencies. 

None.

### License

License for an algorithm? Nah. Public domain.
