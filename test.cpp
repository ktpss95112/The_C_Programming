#include <iostream>

int main(){
    int ax, ay, bx, by, cx, cy;
    std::cin >> ax >> ay >> bx >> by >> cx >> cy;

    std::cout << bx+cx-ax << '\n' << by+cy-ay << '\n' << ax+cx-bx << '\n';
    std::cout << ay+cy-by << '\n' << ax+bx-cx << '\n' << ay+by-cy << '\n';
    
#ifdef DEBUG
    while(1);
#endif
    return 0;
}
