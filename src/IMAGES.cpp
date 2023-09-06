#include"IMAGES.h"
void IMAGES::load() {
	loadimage(&logo, _T("../images/logo.jpg"), 400, 200);
	loadimage(&help, _T("../images/help.jpg"), LENGTH, HEIGHT*2/3);

	loadimage(&gun, _T("../images/gun.jpg"), small_length, small_length);
	loadimage(&knife, _T("../images/knife.jpg"), small_length, small_length);
	loadimage(&machinegun, _T("../images/machinegun.jpg"), small_length, small_length);
	loadimage(&mine, _T("../images/mine.jpg"), small_length, small_length);
	loadimage(&spear, _T("../images/spear.jpg"), small_length, small_length);
	loadimage(&cannon, _T("../images/cannon.jpg"), small_length, small_length);
	loadimage(&shield, _T("../images/shield.jpg"), small_length, small_length);
	loadimage(&gold, _T("../images/gold.jpg"), small_length, small_length);

	loadimage(&stone, _T("../images/stone.jpg"), small_length, small_length);
	loadimage(&trap, _T("../images/trap.jpg"), small_length, small_length);
	loadimage(&iron, _T("../images/iron.jpg"), small_length, small_length);
	loadimage(&mobdoor, _T("../images/mobdoor.jpg"), midium_length, midium_length);
	loadimage(&bossdoor, _T("../images/bossdoor.jpg"), large_length, large_length);
	loadimage(&bossdoor_open, _T("../images/bossdoor_open.jpg"), large_length, large_length);

	loadimage(&eva00[UP], _T("../images/eva00_up.png"), midium_length, midium_length);
	loadimage(&eva00[DOWN], _T("../images/eva00_down.png"), midium_length, midium_length);
	loadimage(&eva00[LEFT], _T("../images/eva00_left.png"), midium_length, midium_length);
	loadimage(&eva00[RIGHT], _T("../images/eva00_right.png"), midium_length, midium_length);
	loadimage(&eva01[UP], _T("../images/eva01_up.png"), midium_length, midium_length);
	loadimage(&eva01[DOWN], _T("../images/eva01_down.png"), midium_length, midium_length);
	loadimage(&eva01[LEFT], _T("../images/eva01_left.png"), midium_length, midium_length);
	loadimage(&eva01[RIGHT], _T("../images/eva01_right.png"), midium_length, midium_length);
	loadimage(&eva02[UP], _T("../images/eva02_up.png"), midium_length, midium_length);
	loadimage(&eva02[DOWN], _T("../images/eva02_down.png"), midium_length, midium_length);
	loadimage(&eva02[LEFT], _T("../images/eva02_left.png"), midium_length, midium_length);
	loadimage(&eva02[RIGHT], _T("../images/eva02_right.png"), midium_length, midium_length);

	loadimage(&average1[UP], _T("../images/average1_up.png"), midium_length, midium_length);
	loadimage(&average1[DOWN], _T("../images/average1_down.png"), midium_length, midium_length);
	loadimage(&average1[LEFT], _T("../images/average1_left.png"), midium_length, midium_length);
	loadimage(&average1[RIGHT], _T("../images/average1_right.png"), midium_length, midium_length);
	loadimage(&average2[UP], _T("../images/average2_up.png"), midium_length, midium_length);
	loadimage(&average2[DOWN], _T("../images/average2_down.png"), midium_length, midium_length);
	loadimage(&average2[LEFT], _T("../images/average2_left.png"), midium_length, midium_length);
	loadimage(&average2[RIGHT], _T("../images/average2_right.png"), midium_length, midium_length);
	loadimage(&sakiel[UP], _T("../images/sakiel_up.png"), large_length, large_length);
	loadimage(&sakiel[DOWN], _T("../images/sakiel_down.png"), large_length, large_length);
	loadimage(&sakiel[LEFT], _T("../images/sakiel_left.png"), large_length, large_length);
	loadimage(&sakiel[RIGHT], _T("../images/sakiel_right.png"), large_length, large_length);
	loadimage(&shamshel[UP], _T("../images/shamshel_up.png"), large_length, large_length);
	loadimage(&shamshel[DOWN], _T("../images/shamshel_down.png"), large_length, large_length);
	loadimage(&shamshel[LEFT], _T("../images/shamshel_left.png"), large_length, large_length);
	loadimage(&shamshel[RIGHT], _T("../images/shamshel_right.png"), large_length, large_length);
	loadimage(&ramiel[UP], _T("../images/ramiel_up.png"), large_length, large_length);
	loadimage(&ramiel[DOWN], _T("../images/ramiel_down.png"), large_length, large_length);
	loadimage(&ramiel[LEFT], _T("../images/ramiel_left.png"), large_length, large_length);
	loadimage(&ramiel[RIGHT], _T("../images/ramiel_right.png"), large_length, large_length);
	loadimage(&gaghiel[UP], _T("../images/gaghiel_up.png"), large_length, large_length);
	loadimage(&gaghiel[DOWN], _T("../images/gaghiel_down.png"), large_length, large_length);
	loadimage(&gaghiel[LEFT], _T("../images/gaghiel_left.png"), large_length, large_length);
	loadimage(&gaghiel[RIGHT], _T("../images/gaghiel_right.png"), large_length, large_length);

	loadimage(&bomb, _T("../images/bomb.png"), midium_length, midium_length);
}