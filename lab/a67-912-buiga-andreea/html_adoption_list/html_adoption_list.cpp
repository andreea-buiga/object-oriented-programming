/**
           .•° ✿ °•.
     created on 17-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "html_adoption_list.h"


void HTMLAdoptionList::write_to_file() {
    ofstream out_file("c:/Users/andre/Documents/GitHub/a67-912-buiga-andreea/dogs_html.html");
    out_file << "<!DOCTYPE html>" << "\n";
    out_file << "<html>" << "\n";

    out_file << "<head>" << "\n";
    out_file << "<title>Dogs Adoption List</title>" << "\n";
    out_file << "</head>" << "\n";

    out_file << "<body>" << "\n";

    out_file << "<table border=\"1\">" << "\n";

    out_file << "<tr>" << "\n";
    out_file << "<td>Breed</td>" << "\n";
    out_file << "<td>Name</td>" << "\n";
    out_file << "<td>Age</td>" << "\n";
    out_file << "<td>Photograph</td>" << "\n";
    out_file << "</tr>" << "\n";

    for (const auto& dog : this->adoption_list) {
        out_file << "<tr>" << "\n";

        out_file << "<td>" << dog.get_breed_dog() << "</td>" << "\n";
        out_file << "<td>" << dog.get_name_dog() << "</td>" << "\n";
        out_file << "<td>" << dog.get_age_dog() << "</td>" << "\n";
        const string& photograph = dog.get_photograph_dog();
        out_file << "<td><a href =" << photograph << ">link</a></td>";

        out_file << "</tr>" << "\n";
    }

    out_file << "</table>" << "\n";
    out_file << "</body>" << "\n";
    out_file << "</html>" << "\n";
    out_file.close();
}

void HTMLAdoptionList::open_in_app() {
    this->write_to_file();
    ShellExecuteA(nullptr, nullptr, "chrome.exe", "c:/Users/andre/Documents/GitHub/a67-912-buiga-andreea/dogs_html.html", nullptr, SW_SHOWMAXIMIZED);
}
