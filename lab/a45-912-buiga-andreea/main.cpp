/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

/**
 * Keep calm and adopt a pet
The “Keep calm and adopt a pet” shelter needs a software application to help them find adoptive parents for the dogs
 they are taking care of. The application can be used in two modes: administrator and user. When the application is
 started, it will offer the option to select the mode.

Administrator mode: The application will have a database that holds all the dogs in the shelter at a given moment.
 The shelter employees must be able to update the database, meaning: add a new dog, delete a dog (when the dog is
 adopted) and update the information of a dog. Each Dog has a breed, a name, an age and a photograph. The photograph
 is memorised as a link towards an online resource (the photograph on the presentation site of the centre). The
 administrators will also have the option to see all the dogs in the shelter.

User mode: A user can access the application and choose one or more dogs to adopt. The application will allow the
 user to:

• See the dogs in the database, one by one. When the user chooses this option, the data of the first dog (breed, name,
 age) is displayed, along with its photograph.
• Choose to adopt the dog, in which case the dog is added to the user’s adoption list.
• Choose not to adopt the dog and to continue to the next. In this case, the information corresponding to the next
 dog is shown and the user is again offered the possibility to adopt it. This can continue as long as the user wants,
 as when arriving to the end of the list, if the user chooses next, the application will again show the first dog.
• See all the dogs of a given breed, having an age less than a given number. If no breed is provided, then all the dogs
 will be considered. The functionalities outlined above apply again in this case.
• See the adoption list.
 */

#include "tests/tests.h"
#include "domain/dog.h"
#include "adoption_list/adoption_list.h"
#include "validator/validator.h"
#include "repository/dog_repository.h"
#include "service/dog_service.h"
#include "ui/ui.h"

int main() {
    Tests::run_all_tests();
    DogRepository dog_repository;
    DogValidator dog_val;
    AdoptionList adoption_list;
    DogService dog_service(dog_repository, dog_val, adoption_list);
    UI ui(dog_service);
    ui.show_ui();

    return 0;
}