# Touchpanel_controller

## 目標
例の音ゲーっぽいコントローラーを作る

## 使うもの
- Pro micro
- 銅テープ
- PSoC4 Prototyping Kit CY8CKIT-049-42xx（使わないかも）
- 適当な抵抗やLEDやアクリル板などなど

## 原理
静電容量方式のタッチパネルを36個ならべてPro microにつなげる。押されたときはキーボードとして認識されるようにKeybord.hを使用する。
