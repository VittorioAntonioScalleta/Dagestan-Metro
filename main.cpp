#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include "sfml-menu.h"
//#include "algorithm.cpp"
#include "Source.cpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
#pragma warning(disable:4996)

constexpr double AverageSpeed = 45.12;
constexpr double AverageTransferTime = 1.5;
constexpr double AverageTimeOfWaiting = 1;

vector<double> algorithm(vector<Station>& Stations, vector<int>& IntermediateStations, int start) {
	int size = Stations.size();
	vector<double> dist(size, pow(10, 6));
	dist[start] = 0;
	vector <bool> visited(size);

	for (int i = 0; i < size; ++i) {
		int nearest = -1;
		for (int v = 0; v < size; ++v) {
			if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v])) {
				nearest = v;
			}
		}

		visited[nearest] = true;

		for (auto& [to, distance] : Stations[nearest].nearstatins) {
			if (dist[to] > dist[nearest] + distance) {
				dist[to] = dist[nearest] + distance;
				IntermediateStations.at(to) = nearest;
			}
		}
	}
	return dist;
}

void PrintPath(vector<Station>& Stations, vector<int>& IntermediateStations, vector<double> dist, int start, int finish) {

	vector<int> VisitedStations;
	for (int i = finish; i != -1; i = IntermediateStations.at(i)) VisitedStations.push_back(i);
	reverse(VisitedStations.begin(), VisitedStations.end());

	double a = 0;
	double Time = (60 * dist[finish] / AverageSpeed) + AverageTimeOfWaiting;


	for (int i = 0; i < VisitedStations.size() - 1; ++i) {
		if (Stations[VisitedStations[i]].line != Stations[VisitedStations[i + 1]].line) {
			Time += AverageTransferTime + AverageTimeOfWaiting;

		}
	}

	cout << "\n\n" << "Время пути:  " << setprecision(4) << Time << " мин." << "\n\n";

	cout << Stations[VisitedStations[0]].name << "   " << Stations[VisitedStations[0]].line << '\n';

	for (int i = 1; i < VisitedStations.size(); ++i) {

		if (Stations[VisitedStations[i - 1]].line != Stations[VisitedStations[i]].line) {
			cout << '\t' << "пересадка с слинии: " << Stations[VisitedStations[i - 1]].line
				<< " на линию: " << Stations[VisitedStations[i]].line << '\n';
		}

		cout << "\tВремя пути до станции " << Stations[VisitedStations[i]].name << " : ";
		cout << setprecision(2) << static_cast<double>(60 * ((dist[VisitedStations[i]] - a) / AverageSpeed)) << " мин." << "\n";
		cout << Stations[VisitedStations[i]].name << "   " << Stations[VisitedStations[i]].line << '\n';

		a += dist[VisitedStations[i]] - a;
	}

}



int main() {
    setlocale(LC_ALL, "Russian");
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::RenderWindow window(sf::VideoMode(1240, 880), "Practice-metro");

    // Поля ввода текста
    sf::RectangleShape inputField1(sf::Vector2f(200, 30));
    inputField1.setFillColor(sf::Color::White);
    inputField1.setOutlineColor(sf::Color::Black);
    inputField1.setOutlineThickness(2);
    inputField1.setPosition(50, 30);

    sf::CircleShape circle_menu1;
    circle_menu1.setRadius(3);
    circle_menu1.setFillColor(sf::Color::White);
    circle_menu1.setOutlineColor(sf::Color::Black);
    circle_menu1.setOutlineThickness(2);
    circle_menu1.setPosition(30, 42);

    sf::CircleShape circle_menu2;
    circle_menu2.setRadius(3);
    circle_menu2.setFillColor(sf::Color::White);
    circle_menu2.setOutlineColor(sf::Color::Black);
    circle_menu2.setOutlineThickness(2);
    circle_menu2.setPosition(30, 94);

    sf::CircleShape circle[99];

    for (int i = 0; i < 73; i++) {
        circle[i].setRadius(5);
        circle[i].setFillColor(sf::Color::Transparent);
        circle[i].setOutlineColor(sf::Color::Transparent);
        circle[i].setOutlineThickness(5);
    }

    circle[0].setPosition(835, 45);
    circle[1].setPosition(835, 80);
    circle[2].setPosition(835, 125);
    circle[3].setPosition(835, 155);
    circle[4].setPosition(835, 185);
    circle[5].setPosition(835, 225);
    circle[6].setPosition(835, 255);
    circle[7].setPosition(835, 315);
    circle[8].setPosition(835, 375);
    circle[9].setPosition(835, 435);
    circle[10].setPosition(835, 495);
    circle[11].setPosition(680, 560);
    circle[12].setPosition(555, 600);
    circle[13].setPosition(425, 650);
    circle[14].setPosition(375, 665);
    circle[15].setPosition(355, 710);
    circle[16].setPosition(355, 745);
    circle[17].setPosition(355, 775);
    circle[18].setPosition(355, 805);
    ////////////////////////////////
    circle[20].setPosition(660, 45);
    circle[21].setPosition(660, 80);
    circle[22].setPosition(660, 125);
    circle[23].setPosition(660, 155);
    circle[24].setPosition(660, 185);
    circle[25].setPosition(660, 225);
    circle[26].setPosition(680, 305);
    circle[27].setPosition(710, 335);
    circle[28].setPosition(720, 420);
    circle[29].setPosition(605, 505);
    circle[30].setPosition(555, 590);
    circle[31].setPosition(555, 645);
    circle[32].setPosition(555, 680);
    circle[33].setPosition(555, 710);
    circle[34].setPosition(555, 745);
    circle[35].setPosition(555, 780);
    circle[36].setPosition(555, 815);
    circle[37].setPosition(555, 850);
    //////////////////////////////////
    circle[38].setPosition(305, 240);
    circle[39].setPosition(380, 315);
    circle[40].setPosition(425, 370);
    circle[41].setPosition(480, 395);
    circle[42].setPosition(735, 435);
    circle[43].setPosition(810, 450);
    circle[44].setPosition(960, 495);
    circle[45].setPosition(960, 595);
    circle[46].setPosition(960, 630);
    circle[47].setPosition(960, 665);
    circle[48].setPosition(960, 690);
    circle[49].setPosition(960, 720);
    /////////////////////////////////
    circle[50].setPosition(595, 490);
    circle[51].setPosition(795, 500);
    circle[52].setPosition(865, 525);
    circle[53].setPosition(960, 500);
    circle[54].setPosition(1060, 470);
    circle[55].setPosition(1100, 510);
    circle[56].setPosition(1140, 550);
    circle[57].setPosition(1180, 590);
    //////////////////////////////////
    circle[58].setPosition(420, 195);
    circle[59].setPosition(450, 230);
    circle[60].setPosition(520, 300);
    circle[61].setPosition(550, 330);
    circle[62].setPosition(580, 365);
    circle[63].setPosition(600, 430);
    circle[64].setPosition(620, 470);
    circle[65].setPosition(715, 565);
    circle[66].setPosition(750, 600);
    circle[67].setPosition(760, 650);
    circle[68].setPosition(760, 690);
    circle[69].setPosition(760, 720);
    circle[70].setPosition(760, 760);
    circle[71].setPosition(760, 810);
    circle[72].setPosition(760, 850);


    sf::RectangleShape inputField2(sf::Vector2f(200, 30));
    inputField2.setFillColor(sf::Color::White);
    inputField2.setOutlineColor(sf::Color::Black);
    inputField2.setOutlineThickness(2);
    inputField2.setPosition(50, 80);

    sf::RectangleShape inputField3(sf::Vector2f(65, 30));
    inputField3.setFillColor(sf::Color::White);
    inputField3.setOutlineColor(sf::Color::Black);
    inputField3.setOutlineThickness(2);
    inputField3.setPosition(110, 135);

    // Шрифт и текст
    sf::Font font;
    if (!font.loadFromFile("gosttypeb.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }

    sf::Texture Image;
    if (!Image.loadFromFile("metro1.jpg"))
    {
        std::cout << "Failed to load image!" << std::endl;
    }
    sf::Sprite Sprite;
    Sprite.setTexture(Image, true);
    Sprite.move(280, 30);
    Sprite.setScale(0.5f, 0.3f);

    sf::Text text1("", font, 20);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(55, 32);

    sf::Text text2("", font, 20);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(55, 82);

    sf::Text buttonText("Готово", font, 20);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(115, 140);

    sf::String inputString1, inputString2, text;

    bool inputField1Active = false;
    bool inputField2Active = false;
    bool donePressed = false;
    bool view = false;

    string line;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                // Проверяем, было ли нажатие на поле ввода 1
                if (inputField1.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    inputField1Active = true;
                    inputField2Active = false;
                    inputField1.setOutlineColor(sf::Color::Green);
                    inputField1.setOutlineThickness(3);
                    inputField2.setOutlineColor(sf::Color::Black);
                    inputField2.setOutlineThickness(2);
                    circle_menu1.setOutlineColor(sf::Color::Green);
                    circle_menu1.setOutlineThickness(5);
                    circle_menu2.setOutlineColor(sf::Color::Black);
                    circle_menu2.setOutlineThickness(2);
                }
                // Проверяем, было ли нажатие на поле ввода 2
                else if (inputField2.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    inputField1Active = false;
                    inputField2Active = true;
                    inputField2.setOutlineColor(sf::Color::Green);
                    inputField2.setOutlineThickness(3);
                    inputField1.setOutlineColor(sf::Color::Black);
                    inputField1.setOutlineThickness(2);
                    circle_menu2.setOutlineColor(sf::Color::Green);
                    circle_menu2.setOutlineThickness(5);
                    circle_menu1.setOutlineColor(sf::Color::Black);
                    circle_menu1.setOutlineThickness(2);
                }
                // Проверяем, было ли нажатие на кнопку "Готово"
                else if (buttonText.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    donePressed = true;
                }
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                    for (int i = 0; i < 73; i++) {
                        if (i == 0) {
                            text = "Девяткино";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 1) {
                            text = "Гражданский-проспект";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 2) {
                            text = "Академическая";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 3) {
                            text = "Политехническая";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 4) {
                            text = "Площадь-Мужества";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 5) {
                            text = "Лесная";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 6) {
                            text = "Выборгская";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 7) {
                            text = "Площадь-Ленина";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 8) {
                            text = "Чернышевская";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 9) {
                            text = "Площадь-Восстания";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 10) {
                            text = "Владимирская";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 11) {
                            text = "Пушкинская";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 12) {
                            text = "Технологический-институт";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 13) {
                            text = "Балтийская";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 14) {
                            text = "Нарвская";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 15) {
                            text = "Кировский-завод";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 16) {
                            text = "Автово";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 17) {
                            text = "Ленинский-проспект";
                            line = "Кировско-Выборгская";
                        }
                        if (i == 18) {
                            text = "Проспект-Ветеранов";
                            line = "Кировско-Выборгская";
                        }
                        ///////////////////////////////////////////////////////////
                        if (i == 20) {
                            text = "Парнас";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 21) {
                            text = "Проспект-просвещения";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 22) {
                            text = "Озерки";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 23) {
                            text = "Удельная";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 24) {
                            text = "Пионерская";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 25) {
                            text = "Чёрная-речка";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 26) {
                            text = "Петроградская";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 27) {
                            text = "Горьковская";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 28) {
                            text = "Невский-Проспект";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 29) {
                            text = "Сенная-Площадь";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 30) {
                            text = "Технологический-Институт";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 31) {
                            text = "Фрунзенская";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 32) {
                            text = "Московские-Ворота";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 33) {
                            text = "Электросила";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 34) {
                            text = "Парк-Победы";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 35) {
                            text = "Московская";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 36) {
                            text = "Звёздная";
                            line = "Москвоско-Петроградская";
                        }
                        if (i == 37) {
                            text = "Купчино";
                            line = "Москвоско-Петроградская";
                        }
                        /////////////////////////////////////////////////////////
                        if (i == 38) {
                            text = "Беговая";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 39) {
                            text = "Зенит";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 40) {
                            text = "Приморская";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 41) {
                            text = "Василеостровская";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 42) {
                            text = "Гостиный-двор";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 43) {
                            text = "Маяковская";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 44) {
                            text = "Площадь-Александра-Невского";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 45) {
                            text = "Елизаровская";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 46) {
                            text = "Ломоносовская";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 47) {
                            text = "Пролетарская";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 48) {
                            text = "Обухово";
                            line = "Невско-Василеостровская";
                        }
                        if (i == 49) {
                            text = "Рыбацкое";
                            line = "Невско-Василеостровская";
                        }
                        ///////////////////////////////////////////////
                        if (i == 50) {
                            text = "Спасская";
                            line = "Правобережная";
                        }
                        if (i == 51) {
                            text = "Достоевская";
                            line = "Правобережная";
                        }
                        if (i == 52) {
                            text = "Лиговский-Проспект";
                            line = "Правобережная";
                        }
                        if (i == 53) {
                            text = "Площадь-Алексадра-Невского";
                            line = "Правобережная";
                        }
                        if (i == 54) {
                            text = "Новочеркасская";
                            line = "Правобережная";
                        }
                        if (i == 55) {
                            text = "Ладожская";
                            line = "Правобережная";
                        }
                        if (i == 56) {
                            text = "Проспект-Большевиков";
                            line = "Правобережная";
                        }
                        if (i == 57) {
                            text = "Улица-Дыбенко";
                            line = "Правобережная";
                        }
                        ////////////////////////////////////////////////////////
                        if (i == 58) {
                            text = "Комендантский-Проспект";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 59) {
                            text = "Старая-Деревня";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 60) {
                            text = "Крестовский-Остров";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 61) {
                            text = "Чкаловская";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 62) {
                            text = "Спортивная";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 63) {
                            text = "Адмиралтейская";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 64) {
                            text = "Садовая";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 65) {
                            text = "Звенигородская";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 66) {
                            text = "Обводный-Канал";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 67) {
                            text = "Волковская";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 68) {
                            text = "Бухарестская";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 69) {
                            text = "Международная";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 70) {
                            text = "Проспект-Славы";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 71) {
                            text = "Дунайская";
                            line = "Фрунзенско-Приморская";
                        }
                        if (i == 72) {
                            text = "Шушары";
                            line = "Фрунзенско-Приморская";
                        }
                        if (circle[i].getGlobalBounds().contains(worldPos) and inputField1Active) {
                            inputString1 = text;
                            text1.setString(inputString1);
                            inputField1Active = false;
                            text = "";
                            inputField1.setOutlineColor(sf::Color::Black);
                            inputField1.setOutlineThickness(2);
                            circle_menu1.setOutlineColor(sf::Color::Black);
                            circle_menu1.setOutlineThickness(2);
                        }
                        if (circle[i].getGlobalBounds().contains(worldPos) and inputField2Active) {
                            inputString2 = text;
                            text2.setString(inputString2);
                            inputField2Active = false;
                            text = "";
                            inputField2.setOutlineColor(sf::Color::Black);
                            inputField2.setOutlineThickness(2);
                            circle_menu2.setOutlineColor(sf::Color::Black);
                            circle_menu2.setOutlineThickness(2);
                        }
                    }
                }
                else {
                    inputField1Active = false;
                    inputField2Active = false;
                }
            }
            else if (event.type == sf::Event::TextEntered) {
                if (inputField1Active) {
                    if (event.text.unicode == 8) // Обработка Backspace
                    {
                        if (!inputString1.isEmpty())
                        {
                            inputString1.erase(inputString1.getSize() - 1, 1);;
                        }
                    }
                    else if (event.text.unicode < 128 || (event.text.unicode >= 1040 && event.text.unicode <= 1103)) // Обработка ASCII и русских символов
                    {
                        inputString1 += event.text.unicode;
                    }
                    text1.setString(inputString1);

                    //if (event.text.unicode == 8 && !inputString1.empty()) // Backspace
                    //    inputString1.pop_back();
                    //else if (event.text.unicode == 13) // Enter (для завершения ввода)
                    //    inputField1Active = false;
                    //else
                    //    inputString1 += event.text.unicode;
                    //text1.setString(inputString1);
                }
                else if (inputField2Active) {
                    if (event.text.unicode == 8) // Обработка Backspace
                    {
                        if (!inputString2.isEmpty())
                        {
                            inputString2.erase(inputString2.getSize() - 1, 1);;
                        }
                    }
                    else if (event.text.unicode < 128 || (event.text.unicode >= 1040 && event.text.unicode <= 1103)) // Обработка ASCII и русских символов
                    {
                        inputString2 += event.text.unicode;
                    }
                    text2.setString(inputString2);
                    std::string text2;
                    text2 = inputString2;
                }
            }
        }

        // Если кнопка "Готово" нажата, выводим значения на экран
        if (donePressed) {
            donePressed = false;
            view = true;
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        sf::Text firtsStat(inputString1, font, 26);
        firtsStat.setFillColor(sf::Color::Black);
        firtsStat.setPosition(25, 190);

        sf::Text lastStat(inputString2, font, 26);
        lastStat.setFillColor(sf::Color::Black);
        lastStat.setPosition(25, 225);

        buttonText.setStyle(sf::Text::Italic);
        text1.setStyle(sf::Text::Italic);
        text2.setStyle(sf::Text::Italic);
        firtsStat.setStyle(sf::Text::Italic);
        lastStat.setStyle(sf::Text::Italic);

        window.clear(sf::Color::White);
        window.draw(inputField1);
        window.draw(inputField2);
        window.draw(inputField3);
        window.draw(text1);
        window.draw(text2);
        window.draw(buttonText);
        window.draw(Sprite);
        window.draw(circle_menu1);
        window.draw(circle_menu2);
        for (int i = 0; i < 73; i++) {
            window.draw(circle[i]);
        }
        if (view) {
            window.draw(firtsStat);
            window.draw(lastStat);
        }


        window.display();
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

    freopen("текст.txt", "r", stdin);

    int StationsCount, DistCount;
    cin >> StationsCount >> DistCount;

    vector<Station> Stations(StationsCount);
    //cout << Stations.size() << '\n';
    vector<int> IntermediateStations(StationsCount, -1);

    //ifstream input;          // поток для записи
    //input.open("Текст.txt");


    for (int i{}; i < DistCount; ++i) {
        int number1, number2;
        double distance;
        string name1, line;

        cin >> number1 >> name1 >> line;
        cin >> number2 >> distance;

        Stations[number1].name = name1;
        Stations[number1].number = number1;
        Stations[number1].line = line;
        Stations[number1].nearstatins.push_back({ number2, distance });
        Stations[number2].nearstatins.push_back({ number1, distance });
    }

    //cout << Stations[0].nearstatins.size() << '\n';
    //cout << Stations.size() << '\n';
    int start{};
    int finish{};
    string start1, finish1;
    //cin >> start1 >> finish1;
    start1 = inputString1;
    finish1 = inputString2;
    for (int i{}; i < StationsCount; ++i) {
        if (start1 == Stations[i].name) start = i;
        else if (finish1 == Stations[i].name) finish = i;
    }


    vector<double> dist = algorithm(Stations, IntermediateStations, start);

    vector<int> VisitedStations;
    for (int i = finish; i != -1; i = IntermediateStations.at(i)) VisitedStations.push_back(i);
    reverse(VisitedStations.begin(), VisitedStations.end());

    double a = 0;
    double Time = (60 * dist[finish] / AverageSpeed) + AverageTimeOfWaiting;


    for (int i = 0; i < VisitedStations.size() - 1; ++i) {
        if (Stations[VisitedStations[i]].line != Stations[VisitedStations[i + 1]].line) {
            Time += AverageTransferTime + AverageTimeOfWaiting;

        }
    }

    cout << "\n\n" << "Время пути:  " << setprecision(4) << Time << " мин." << "\n\n";

    cout << Stations[VisitedStations[0]].name << "   " << Stations[VisitedStations[0]].line << '\n';

    for (int i = 1; i < VisitedStations.size(); ++i) {

        if (Stations[VisitedStations[i - 1]].line != Stations[VisitedStations[i]].line) {
            cout << "------------------------|" << "пересадка с слинии: " << Stations[VisitedStations[i - 1]].line
                << " на линию: " << Stations[VisitedStations[i]].line << '\n';
        }

        cout << "\t\t\tВремя пути до станции " << Stations[VisitedStations[i]].name << " : ";
        cout << setprecision(2) << static_cast<double>(60 * ((dist[VisitedStations[i]] - a) / AverageSpeed)) << " мин." << "\n";
        cout << Stations[VisitedStations[i]].name << "   " << Stations[VisitedStations[i]].line << '\n';

        a += dist[VisitedStations[i]] - a;
    }

    return 0;
}