#include "chess/board_serializer.h"

#include "chess/piece.h"

#include <numeric>

namespace chess::ui::cmd
{

    std::string serialize(const chess::game::Board &board)
    {

        std::string board_string = "";
        int index = 0;
        int width = board.width();

        std::for_each(board.cbegin(), board.cend(), [&index, &width, &board_string](const auto &field)
                      {
                          if (field.has_value())
                          {
                              const chess::game::Piece piece = field.value();
                              board_string += "| " + chess::game::to_string(piece) + " ";
                          }
                          else
                          {
                              board_string += "|    ";
                          }
                            
                          if ((index+1) % width == 0)
                          {
                              board_string += "| \n";
                          }
                          index++; });
        return board_string;
    }
}
