# Computer Programming I Homework 1
## 作者資訊
 - 姓名: 姚承希
 - 學號: 41347014S

## 如何編譯程式並建立執行檔
使用指令 `make`或執行以下指令
```
gcc hw0101.c -o hw0101
gcc hw0102.c -o hw0102
gcc hw0103.c -o hw0103
gcc hw0104.c -o hw0104
gcc hw0105.c -o hw0105
```

## 如何執行程式
1. `./hw0101`
2. `./hw0102`
3. `./hw0103`
4. `./hw0104`
5. `./hw0105`

## 程式介紹
1. Print Colorful Words  
印出歌曲「Sun and Moon」的歌詞，並將Kim的歌詞標示為紅色，Chris的歌詞標示為藍色，合唱的標示為綠色。

2. A Simple Math Problem  
這個程式可以幫助你解出一個數學填空問題。  
輸入第一個數包含x: \_x\_，再輸入第二個數字包含y、z: y_z，最後輸入一個和，就可以幫你解出x、y、z。

3. Flip an Octal Number  
將使用者輸入的數轉換成8進位，再將8進位的數反轉並轉回10進位

4. Poker Hands  
這個程式可以協助判斷5張撲克牌的牌型

5. Binary Variable  
這個程式可以將2進位記憶體轉換成三種形式輸出:
    1. integer
    2. unsigned integer
    3. float

## 1-6 Bonus: Makefile for Multiple files
在Makefile中的每一項指令前加上`-`，當程式編譯時發生錯誤也會繼續將全部的指令執行完畢。
