#include "Barrier.h"
#include "DxLib.h"

Barrier::Barrier() :image(NULL), life_span(1000)
{
	//画像の読込み
	image = LoadGraph("Resource/image/barrier.png");

	//エラーチェック
	if (image == -1)
	{
		throw("Resource/images/barrier.pngがありません\n");
	}
}

Barrier::~Barrier()
{
	//読み込んだ画像を削除
	DeleteGraph(image);
}

//描画処理
void Barrier::Draw(const Vector2D& location)
{

}
