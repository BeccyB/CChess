#include "view/cmd_output.h"
#include "model/chess_game.h"
#include "model/chess_piece.h"

namespace view {

    void show(const std::string message) {
        std::printf("%s\n", message.c_str());
    }

    void show_instructions() {
        show("Input <a-h><1-8> or Q/q/x to quit. Pres i for instructions.");
    }

    void show_game_start() {
        show("****************************************");
        show("Starting new game :) Let the game begin!");
        show("****************************************");

        show("");
        show_instructions();
        show("");
    }

    void show_game_wone(model::Colour colour) {
        auto msg = fmt::format("Check Mate!!! {} wins! :) :) :) :)",
                               model::to_string(colour));
        view::show(msg);
    }

    void show_game_end() {

        show("");
        show("****************************************");
        show("Stoping Game. Good Bye!");
        show("****************************************");
    }

    void show_next_player(model::Colour colour) {
        show(fmt::format("{} player, it is your turn:",
                         model::to_string(colour)));
    }

    void show(const model::Coordinate start,
              const model::Coordinate destination) {

        show(fmt::format("Moving {}{} -> {}{}", start.get_row(),
                         start.get_column(), destination.get_row(),
                         destination.get_column()));
    }

    void show(const model::ChessMoveStatus status) {

        switch (status) {
        case model::ChessMoveStatus::NOT_OCCUPID:
            show("You selected an empty field.");
            break;
        case model::ChessMoveStatus::OCCUPID:
            show("You selected an occupied field.");
            break;
        case model::ChessMoveStatus::VALID:
            show("Valid input.");
            break;
        }
    }

    void show(const model::Board &board) {

        using namespace std;
        std::string letter_header = "  |  a  b  c  d  e  f  g  h |  ";
        std::string horizontal_separator = "--|-------------------------|--";
        std::string empty_field_display = "   ";

        auto row_index = model::constants::MAX_INDEX;
        cout << letter_header << endl;
        cout << horizontal_separator << endl;
        for (const auto rows : board.get_fields()) {
            // display numbers on the left
            cout << row_index << " | ";
            for (const auto col : rows) {
                if (col == 'e') {
                    cout << empty_field_display;
                } else {
                    cout << " " << col << " ";
                }
            }
            // display numbers on the right
            cout << "| " << row_index << endl;
            row_index--;
        }
        cout << horizontal_separator << endl;
        cout << letter_header << endl;
        cout << endl;
    }

} // namespace view