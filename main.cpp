#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>

struct DataFilm{
    std::string name;
    std::vector<std::string> country;
    int year;
    std::string studios;
    std::vector<std::string> author_script;
    std::vector<std::string>  director;
    std::vector<std::string> producer;
    std::map<std::string, std::string> starring;
};

void generate(const std::string* path){
    std::ofstream file(*path);
    nlohmann::json data;
    data["country"] = {"USA", "Australia"};
    data["data create"] = "1999";
    data["studios"] = "Fox Studios";
    data["author_script"] = {"Лилли Вачовски", "Лана Вачовски"};
    data["director"] = {"Лилли Вачовски", "Лана Вачовски"};
    data["producer"] = {"Лилли Вачовски", "Лана Вачовски", "Джоэл Силвер", "Брюс Берман",
                        "Дэн Краччиоло", "Кэрол Хьюз", "Эндрю Мэйсон", "Ричард Мириш",
                        "Барри М. Осборн", "Эрвин Стофф"};
    data["starring"] = {{"Киану Ривз" , "Нео"},
                        {"Лоуренс Фишберн", "Морфеус"},
                        {"Кэрри-Энн Мосс", "Тринити"},
                        {"Хьюго Уивинг", "Агент Смит"},
                        {"Джо Пантолиано", "Сайфер"}};
    file << data;
}

std::vector<std::string> json_to_vector(nlohmann::json json){
    std::vector<std::string> new_vec;
    for (auto it = json.begin(); it != json.end(); ++it){
        new_vec.emplace_back(it.value());
    }
    return new_vec;
}
void showDataInfoActor(const std::vector<DataFilm>& films, const std::string& actor){
    for (const auto& film : films) {
        if(film.starring.count(actor) > 0){
            std::cout << "Film: " << film.name << " role: " << film.starring.at(actor) << std::endl;
        }
    }
}

std::vector<DataFilm> loadData(const std::string* path){
    std::ifstream json(*path);
    std::vector<DataFilm> films;
    nlohmann::json dict;
    json >> dict;
    int ind = 0;
    for (auto it = dict.begin(); it != dict.end(); ++it, ++ind) {
        films.emplace_back(DataFilm());
        films[ind].name = it.key();
        films[ind].year = it.value()["data create"];
        films[ind].starring = it.value()["starring"];
        films[ind].country = json_to_vector(it.value()["country"]);
        films[ind].director = json_to_vector(it.value()["director"]);
        films[ind].producer = json_to_vector(it.value()["producer"]);
        films[ind].studios = it.value()["studios"];
    }
    return films;
}

int main() {
    /*Task 1*/
    std::string path = "/home/sergeimakarov/CLionProjects/Json/record.json";
    generate(&path);
    /*Task 2*/
/*    std::string path = "/home/sergeimakarov/.config/JetBrains/CLion2021.2/scratches/films.json";
    std::vector<DataFilm> films = loadData(&path);
    showDataInfoActor(films, "Киану Ривз");*/
}
