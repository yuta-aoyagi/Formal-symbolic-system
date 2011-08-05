/**
 * @file main.c
 * @brief FSSのメインプログラム. the main program of FSS.
 * @author Yuta Aoyagi
 * @since 2011-07-28
 */

#include <guigui01.h>
#include <stddef.h>

/* ************************************************
 *  ライブラリ補完. the complement to poor library.
 * ************************************************ */

/**
 * @brief 動的に @a size バイトのメモリを確保し, それへのポインタを返す.
 * allocate dynamic memory @a size bytes, and return a pointer to it.
 *
 * メモリの確保に失敗した場合, NULLが返されるか, またはプログラムが終了する.
 * if fail allocating memory, reuturn NULL or make the program exit.
 * @param[in] size 確保するメモリの大きさ. the size of memory to be allocated.
 * @retval NULL 確保に失敗したとき. when fail to allocate.
 * @retval !=NULL 確保されたメモリへのポインタ. a pointer to the allocated memory.
 */
void *my_malloc(size_t size) {
	return jg01_malloc(size);
}

/**
 * @brief ポインタ @a ptr が指す領域を開放する. release the area @a ptr points.
 * @param[in,out] ptr 開放する領域. the area to be release.
 */
void my_free(void *ptr) {
	// to do memory release. //	jg01_mfree(ptr);
}

/* ************************************************
 *  プログラム本体. the main part of the program.
 * ************************************************ */

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
