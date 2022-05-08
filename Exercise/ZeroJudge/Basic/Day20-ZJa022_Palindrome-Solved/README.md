
# Palindrome 迴文
題目編號：`ZJ a022`<br>
題目標籤：`#String`<br>
題目來源：[ZeroJudge a022](https://zerojudge.tw/ShowProblem?problemid=a022)<br>
題目出處：[管理者： [jiangsir](https://zerojudge.tw/UserStatistic?id=2)  ]

## Problem 題目
迴文的定義為正向，反向讀到的字串均相同:<br>
如：abba、abcba... 等就是迴文，請判斷一個字串是否是一個迴文？

* 輸入說明：輸入資料共一行包含一個字串(長度 < 1000)
* 輸出說明：針對每一行輸入字串輸出 yes or no

## Sample 測資範例
### # sample 1
|Input |Output |
|:-----|:------|
|abba |yes
### # sample 2
|Input |Output |
|:-----|:------|
|abcd |no

## 測資資訊
* 參考：題目來源

## 提示
* Null

## 題意解析
問題在於如何分割字串，然後再將分割後的兩個字串進行比較。
