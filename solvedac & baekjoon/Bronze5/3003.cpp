#include <iostream>

int main()
{
	int king(1), queen(1), rook(2), bishop(2), knight(2), pawn(8);

	int k, q, r, b, kn, p;
	std::cin >> k >> q >> r >> b >> kn >> p;

	std::cout << (king - k) << " " << (queen - q) << " " << (rook - r) << " " << (bishop - b) << " " << (knight - kn) << " " << (pawn - p) << "\n";
	
	return 0;
}