#include"SceneManager.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"
#include"TitleScene.h"
#include"GameMainScene.h"
#include"ResultScene.h"
#include"HelpScene.h"
#include"RankingDispScene.h"
#include"RankingInputScene.h"

SceneManager::SceneManager() :current_scene(nullptr)
{

}

SceneManager::~SceneManager()
{

}

//シーンマネージャー機能：初期化処理
void SceneManager;; Initialize()
{
	//ウィンドウのタイトルを設定
	SetMainWindowText("Drive&Avoid");

	//ウィンドウモードで起動
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		throw("ウィンドウモードで起動できませんでした\n");
	}

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		throw("Dxライブラリが初期化できませんでした\n");
	}

	//描画先指定処理
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)
	{
		throw("描画先の指定ができませんでした\n");
	}

	//タイトルシーンから始める
	ChangeScene(eSceneType::E_TITLE);
}

//シーンマネージャー機能：更新処理
void SceneManager::Update()
{
	//フレーム開始時間（マイクロ秒）を取得
	LONGLONG start_time = GetNowHiPerformanceCount();

	//メインループ
	while (ProcessMessage() != -1)
	{
		//現在時間を取得
		LONGLONG now_time = GetNowHiPerFormanceCount();

		//1フレーム当たりの時間を更新する
		start_time = now_time;

		//入力機能：更新処理
		InputControl::Update();

		//更新処理(戻り値は次のシーン情報)
		eSceneType next = current_scene->Update();

		//描画処理
		Draw();

		//エンドが選択されていたら、ゲームを終了する
	}
}