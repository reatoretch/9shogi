#include <DxLib.h>
#include <iostream>

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{
    ChangeWindowMode( TRUE );//Windowモードに設定(FALSEのときは全画面表示)
    SetGraphMode( 600 , 600 , 32 );//画面サイズ指定
    SetOutApplicationLogValidFlag( FALSE ) ;//Log.txtを生成しないように設定
    if(DxLib_Init() == 1){return -1;}//初期化に失敗時にエラーを吐かせて終了

    int backImage = LoadGraph("images/field.png");
    int enemyImage = LoadGraph("images/enemy.png");
    int playerImage = LoadGraph("images/player.png");

    while( ProcessMessage()==0 )
    {
        ClearDrawScreen();//裏画面消す
        SetDrawScreen( DX_SCREEN_BACK ) ;//描画先を裏画面に

        DrawGraph(0, 0, backImage, FALSE);
        DrawGraph(210, 10, enemyImage, FALSE);
        DrawGraph(210, 410, playerImage, FALSE);

        ScreenFlip();//裏画面を表画面にコピー
    }

    DxLib_End();
    return 0;
}
