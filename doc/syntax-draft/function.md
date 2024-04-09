# 関数
関数は
```
func 関数名(型 引数, ...) : 戻り値の型 {
    // Code here...
}
```
の形式で定義する。
## 引数の値
明示的に参照を示さない限り、値はコピーされる。

型の所には[型名](./type)を書く。
配列の場合は記法がいくつか
```
// 要素が3つのint32配列のみ受け付ける
func function1(int32[3] position) : bool {}

// 要素数任意のint32配列を受け付ける
func function1(int32[] position) : bool {}
```