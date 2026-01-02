# Electronic Panic

一个基于 **C++ / SFML 3.x** 的 2D 解谜 + 移动类游戏项目。  
玩家在不同房间中移动，通过改变自身状态、与电子元件和逻辑门交互，解锁地图并前进。

---

## 🎮 游戏简介

- 玩家在地图中自由移动（W/A/S/D）
- 角色具有 **正 / 负 两种状态**
- 不同状态可与不同电子元件、逻辑门产生交互
- 房间之间通过传送点切换
- 包含动画角色、动态背景与背景音乐

---

## 🛠 技术栈 & 依赖库

### 使用语言
- **C++17 / C++20**

### 图形与音频
- **SFML 3.x**
  - `sfml-graphics`
  - `sfml-window`
  - `sfml-system`
  - `sfml-audio`

### 标准库
- `<vector>`
- `<string>`
- `<memory>`
- `<optional>`
- `<iostream>`

---

## 📁 项目结构

```text
ElectronicPanic/
│
├─ assets/
│   ├─ .*png        
│   ├─ .*jpg        
│   ├─ .*ogg
│   ├─ .*jpeg
│   ├─ .*ttf
│   └─ .*otf                  
│
├─ src / include /
│   ├─ Game.cpp / Game.h
│   ├─ Player.cpp / Player.h
│   ├─ Wall.cpp / Wall.h
│   ├─ Room.cpp / Room.h
│   ├─ *.cpp / *.h
│   └─ main.cpp
│
└─ README.md
```
---
## 使用方法
```bash
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
./build\Maze
```

## ❤️ 支持者

美术支持：
<a href="https://github.com/libiwolve">
  <img src="https://github.com/libiwolve.png" width="50" />
</a>

