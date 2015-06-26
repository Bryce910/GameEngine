#pragma once
#include "linker.h"

class draw /*: public player, public menu, public projectile */
{
public:
	draw();
	~draw();
	void FdrawMenu();
	void FdrawCharacter();
	void FdrawProjectile();
};

