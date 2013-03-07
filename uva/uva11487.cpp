Do 1x BFS to find out how many items(k).
Do k times BFS to find APSP.
Int minD[k][k] = {…};
Int memo[n][n], sum = 1;
Int curX, curY;
For (A to B, B to C………….second last to last){
         set curX and curY to destination’s coordinate
         memo[n][n] = {-1…};
         sum *= dp(sourceX, sourceY, minD[sourceIndex][DestIndex]);
}
Return Sum;

Int dp(int x, int y, int steps_left){
     if (steps_left == 0 && x == curX && y == curY)
             return 1;
      if (steps_left < 0)
             return 0;
      memo[x][y] = 0;
      for all directions, if not out of grid and is empty
                memo[x][y] += dp(x+a, y+b, steps_left -1);
      return memo[x][y];
}
