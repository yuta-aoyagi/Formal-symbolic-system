/**
 * @file main.c
 * @brief FSSのメインプログラム. the main program of FSS.
 * @author Yuta Aoyagi
 * @since 2011-07-28
 */

#include <guigui01.h>

/// g01_bss1a1 が指す領域の大きさ. the size of the area g01_bss1a1 pointing.
#define BSS_SIZE (2 * 1024 * 1024)

/**
 * @brief メイン関数. the main function.
 * @note
 * 現在はただ入力ファイルをダンプし正常終了するだけの処理しかない.
 * It just print the content of the input file and exit successfully now.
 */
void G01Main(void) {
	static const unsigned char cmdusage[] = {
		0x86, 0x50,
		0x00, 's', 0x0c, 6, 's', 'y', 'n', 't', 'a', 'x',
		0x40,
	};
	char *b = g01_bss1a1;
	g01_setcmdlin(cmdusage);
	g01_getcmdlin_fopen_s_0_4(0);
	jg01_fread0_4(BSS_SIZE, b);
	g01_putstr0(b);
}
