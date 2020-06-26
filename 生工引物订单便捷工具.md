# 生工引物订单便捷工具

# 使用方法

1. Macos(苹果)系统下点击SGOrder，windows系统下点击SGOrder.exe将引物信息文件直接拖放到终端窗口，按下回车键，引物名称(ID)，对应序列，引物格式文件有两种(以KASP标记为例子,普通引物同样如此)：

   - 中间用英文**逗号**隔开(csv文件)

   ```json
   AX-17357,gtggtAatCTttgatcaCGaACA,gtggtAatCTttgatcaCGaACG,tggttgccacaaagacTAATGT
   AX-10893,actcggagaagaaaatgccA,actcggagaagaaaatgccG,tcgttgtcttcggagtttcC
   AX-10891,cgagatgtaatgtgtgggactG,cgagatgtaatgtgtgggactA,agcggctactgacgatcT
   ```

   - 从excel中直接复制到文本中(含制表符‘\t’)

   ```json
   AX-17357	gtggtAatCTttgatcaCGaACA	gtggtAatCTttgatcaCGaACG	tggttgccacaaagacTAATGT
   AX-10893	actcggagaagaaaatgccA	actcggagaagaaaatgccG	tcgttgtcttcggagtttcC
   AX-10891	cgagatgtaatgtgtgggactG	cgagatgtaatgtgtgggactA	agcggctactgacgatcT
   ```

2. 选择引物类别:1或2,然后按下回车键，生成对应的生工引物格式文件(含有_mod)，用自带文本编辑器或者notepad++(win7),或者sublime(macos),然后将其复制进生工订单excel中，省去手动操作的麻烦。

1. ![image-20200626143545928](/Users/jy/Library/Application Support/typora-user-images/image-20200626143545928.png)

![image-20200626143638218](/Users/jy/Library/Application Support/typora-user-images/image-20200626143638218.png)

![image-20200626145514743](/Users/jy/Library/Application Support/typora-user-images/image-20200626145514743.png)

