#pragma once

#include <optional>
#include "model/coordinate.h"
#include "model/board.h"

namespace model {

    enum class ChessMoveStatus {
        NOT_OCCUPID, // there is not chess pice that can be selected
        OCCUPID,     // the destination field is occupied
        VALID,       // it is a valid selection
    };

    class GameMove {
      public:
        GameMove(const Coordinate start, const Coordinate destination)
            : start_(start), destination_(destination){};

        ~GameMove() = default;

        GameMove(const GameMove &other)
            : start_(other.start_), destination_(other.destination_) {
        }

        const std::pair<model::Coordinate, model::Coordinate>
        coordinates() const;

        const Coordinate &start() const {
            return start_;
        }

        const Coordinate &destination() const {
            return destination_;
        }

        bool is_equal() const;

      private:
        Coordinate start_;
        Coordinate destination_;
    };
} // namespace model