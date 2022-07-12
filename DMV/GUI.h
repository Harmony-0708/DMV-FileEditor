#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "harmonylib.h"

class GUI
{
public:
	int straightline{ 186 }; // ║
	int bottomintersection{ 203 }; // ╦
	int upperintersection{ 202 }; // ╩
	int rightintersection{ 185 }; // ╣
	int leftintersection{ 204 }; // ╠
	int fullintersection{ 206 }; // ╬
	int cornertplf{ 201 }; // ╔
	int cornertprt{ 187 }; // ╗
	int cornerbtlf{ 200 }; // ╚
	int cornerbtrt{ 188 }; // ╝
	int across{ 205 }; // ═
	int lightstraightline{ 179 }; // │
	int lightbottomintersection{ 194 }; // ┬
	int lightupperintersection{ 193 }; // ┴
	int lightrightintersection{ 180 }; // ┤
	int lightleftintersection{ 195 }; // ├
	int lightfullintersection{ 197 }; //┼
	int lightcornertplf{ 218 }; // ┌
	int lightcornertprt{ 191 }; // ┐
	int lightcornerbtlf{ 192 }; // └
	int lightcornerbtrt{ 217 }; // ┘
	int lightacross{ 196 }; // ─
	int thicktothinbottomintersection{ 207 }; // ╧
	int thicktothinupperintersection{ 209 }; // ╤
	int thicktothinrightintersection{ 181 }; // ╡
	int thicktothinleftintersection{ 199 }; // ╟
	int thicktothinfullintersection{ 216 }; // ╪
	int thicktothincornertplf{ 214 }; // ╓
	int thicktothincornertprt{ 184 }; // ╕
	int thicktothincornerbtlf{ 211 }; // ╙
	int thicktothincornerbtrt{ 190 }; //  ╛
	int thintothickbottomintersection{ 208 }; // ╨
	int thintothickupperintersection{ 210 }; // ╥
	int thintothickrightintersection{ 182 }; // ╢
	int thintothickleftintersection{ 198 }; // ╞
	int thintothickfullintersection{ 215 }; // ╫
	int thintothickcornertplf{ 213 }; // ╒
	int thintothickcornertprt{ 183 }; // ╖
	int thintothickcornerbtlf{ 212 }; // ╘
	int thintothickcornerbtrt{ 189 }; // ╜
	int thickfull{ 219 }; // █
	int thickbottom{ 220 }; // ▄
	int thicktop{ 223 }; // ▀
	int thickleft{ 221 }; // 
	int thickright{ 222 }; // 



	void MakeBox(int input, int style = 0, bool wordWrap = false, int wordWrapLimit = 0);
	void MakeBox(float input, int style = 0, bool wordWrap = false, int wordWrapLimit = 0);
	void MakeBox(std::string input, int style = 0, bool wordWrap = false, int wordWrapLimit = 0);
	void MakeBox(std::vector<std::string> input, int style = 0, bool wordWrap = false, int wordWrapLimit = 0);
	void MakeBox(std::vector<int> input, int style = 0, bool wordWrap = false, int wordWrapLimit = 0);
	void MakeBox(std::vector<float> input, int style = 0, bool wordWrap = false, int wordWrapLimit = 0);

	void GenerateMenu(std::string header, std::vector<std::string> menuOptions, std::string footer = "");

	void GenerateGrid(std::vector<std::string> objects, int height = 0, int width = 0);
};

