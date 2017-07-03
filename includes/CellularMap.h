#pragma once
/*!
* A simple but effective Cellular Automata 2D Map implementation.
*
* @author   Davide Aversa <thek3nger@gmail.com>
* @version  1.0
*/

/*!
 * Implementation of a Cellular Automata cave-like map generator.
 * 
 * USAGE EXAMPLE:
 *      CellularMap cm(50,40,40);
 *      cm.evolveMap();
 */
class CellularMap
{
public:

    /*!
     * Specifies the rule set used by the cellular automata.
     */
    enum RuleSet {
        CM_CONSERVATIVE,    //! Corresponding to R1(p) >= 5 || R2(p) <= 1
        CM_SMOOTH           //! Corresponding to R1(p) >= 5
    };

    /*!
     * Constructor.
     * 
     * @param width                 Desired map width.
     * @param height                Desired map height.
     * @param walls_probability     Initial percentage of walls.
     */
    CellularMap(int width, int height, int walls_probability);
    ~CellularMap();
    
    /*!
     * Execute a step of the automata algorithm creating the cave or
     * Smoothing the existing ones.
     */
    void evolveMap();

    /*!
     * Execute a step of the automata algorithm creating the cave or
     * Smoothing the existing ones using a specific rule set.
     */
    void evolveMap(RuleSet rule);

    /*!
     * Get the element in position <x,y>.
     *
     * @param x The x coordinate.
     * @param y The y coordinate.
     * @return The element in <x,y>.
     */
    int inline getElement(int x, int y) { return map[getIndex(x, y)]; }

    /*!
     * Get the map width.
     */
    int inline getWidth () { return width; }

    /*!
     * Get the map height.
     */
    int inline getHeight() { return height; }

private:

    int* map;               // Store the map.
    int width;              // The map width.
    int height;             // The map height.
    int walls_probability;  // The initial amount of walls.

    /*
    * Initialize the map with a random amount of walls.
    */
    void randomFill();

    /*
    * Execute the Cellular Automata rules on every tile of the map.
    *
    * @return The new value of tile <x,y>.
    */
    int  placeWallLogic(int x, int y, RuleSet rule);

    /*
    * Get the sum of adjacent walls to a given tile <x,y>
    *
    * @param x          The x coordinate in the map.
    * @param y          The y coordinate in the map.
    * @param scope_x    The search scope radius in x direction.
    * @param scope_y    The search scope radius in y direction.
    * @return           The number of walls in the scope of <x,y>.
    */
    int  getAdjacentWalls(int x, int y, int scope_x, int scope_y);

    /*
    * Check if a tile is out of the map.
    *
    * @param x  The x coordinate in the map.
    * @param y  The y coordinate in the map.
    * @return   True iff <x,y> is out of the map. False otherwise.
    */
    bool isOutOfBound(int x, int y);

    /*
    * Get the rom-major index of the tile <x,y>
    *
    * @param x  The x coordinate in the map.
    * @param y  The y coordinate in the map.
    * @return   The row-major index of <x,y>.
    */
    int  inline getIndex(int x, int y) { return x + y*width; }

    /*
    * Chek if the tile is a Wall.
    *
    * @param x  The x coordinate in the map.
    * @param y  The y coordinate in the map.
    * @return   True iff <x,y> is a wall. False otherwise.
    */
    bool isWall(int x, int y);

};
