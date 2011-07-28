/**
 * @file main.c
 * @brief FSSのメインプログラム. the main program of FSS.
 * @author Yuta Aoyagi
 * @since 2011-07-28
 */

#include <guigui01.h>

/**
 * @brief メイン関数. the main function.
 * @note
 * 現在はただメッセージを出力し正常終了するだけの処理しかない.
 * It just print a message and exit successfully now.
 */
void G01Main(void) {
	g01_putstr0("Hello, world!\n");
}
