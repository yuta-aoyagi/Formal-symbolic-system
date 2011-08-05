/**
 * @file main.c
 * @brief FSSのメインプログラム. the main program of FSS.
 * @author Yuta Aoyagi
 * @since 2011-07-28
 */

#include <guigui01.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* ************************************************
 *  ライブラリ補完. the complement to poor library.
 * ************************************************ */

/**
 * @brief 動的に @a size バイトのメモリを確保し, それへのポインタを返す.
 * allocate dynamic memory @a size bytes, and return a pointer to it.
 *
 * メモリの確保に失敗した場合, NULLが返されるか, またはプログラムが終了する.
 * if fail to allocate memory, reuturn NULL or make the program exit.
 * @param[in] size 確保するメモリの大きさ. the size of memory to be allocated.
 * @retval NULL メモリの確保に失敗したとき. when fail to allocate memory.
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

/**
 * @brief グローバル変数の代わりに使う作業領域の型.
 * a type of working area used instead of global variables.
 */
struct WORK {
	char *syntax_file;	///< 文法定義ファイルの内容. the content of the syntax file.
};

/// g01_bss1a1 が指す領域の大きさ. the size of the area g01_bss1a1 pointing.
#define BSS_SIZE (2 * 1024 * 1024)

/**
 * @brief コマンドラインで与えられたファイルを読む. read a file given from command line.
 *
 * @a arg_no 番目のコマンドライン引数で与えられたファイルを開き, その内容を一時領域に読み込んで,
 * ::my_malloc で確保されるバッファのコピーへのポインタを返す.
 * open the file given @a arg_no -th command line argument, read its content to the temporary buffer,
 * and return a pointer to its copy allocated by ::my_malloc.
 *
 * ファイルオープンと読み込みのいずれかに失敗すると, プログラムは終了する.
 * バッファの確保に失敗すると, NULLを返すかプログラムが終了する.
 * if fail to open the file or to read it, make the program exit.
 * if fail to allocate buffer, return NULL or make the program exit.
 * @param[in] arg_no コマンドライン引数の番号. the number in command line argument.
 * @retval NULL バッファの確保に失敗したとき. when fail to allocate buffer.
 * @retval !=NULL ファイルの内容へのポインタ. これは ::read_file の呼び出し側が開放しなければならない.
 * a pointer to the content of the file. all code calling ::read_file must release the area.
 */
static void *read_file(int arg_no) {
	char *buf, *bss = g01_bss1a1;
	int len;
	g01_getcmdlin_fopen_s_0_4(arg_no);
	len = jg01_fread1f_4(BSS_SIZE, bss);
	buf = my_malloc(len + 1);
	if (buf != NULL) {
		memcpy(buf, bss, len);
		buf[len] = '\0';
	}
	return buf;
}

/**
 * @brief プログラムの初期化処理. initialize the program.
 *
 * コマンドライン引数の設定を行い, 文法定義ファイルを読む.
 * configure command line arguments, and read the syntax file.
 * @param[out] pw 作業領域へのポインタ. a pointer to the working area.
 */
static void init(struct WORK *pw) {
	static const unsigned char cmdusage[] = {
		0x86, 0x50,
		0x00, 's', 0x0c, 6, 's', 'y', 'n', 't', 'a', 'x',
		0x40,
	};
	g01_setcmdlin(cmdusage);
	pw->syntax_file = read_file(0);
}

/**
 * @brief メイン関数. the main function.
 * @note
 * 現在はただ入力ファイルをダンプし正常終了するだけの処理しかない.
 * It just print the content of the input file and exit successfully now.
 */
void G01Main(void) {
	struct WORK w;
	init(&w);
	g01_putstr0(w.syntax_file);
	my_free(w.syntax_file);
}
