#pragma once

#include <optional>
#include "model/coordinate.h"
#include "model/board.h"

namespace model {

    struct GameMove {

        enum class ValidityStatus {
            NOT_OCCUPID,  // there is not chess pice that can be selected
            OCCUPID,      // the destination field is occupied
            OUT_OF_REACH, // the destination field is out of reach for the chess
                          // piece
            VALID,        // it is a valid selection
        };

        std::optional<model::Coordinate> start;
        std::optional<model::Coordinate> destination;

        // other moved might require other inputs besides start and
        // destination???
        bool ready() const {
            return start.has_value() && destination.has_value();
        }

        const std::pair<model::Coordinate, model::Coordinate> get() const {
            return {start.value(), destination.value()};
        }

        ValidityStatus set_if_valid(const model::Board &board,
                                    const model::Coordinate coordinate) {

            if (!start.has_value()) {
                // first user must input start
                if (!board.is_occupied(coordinate)) {
                    return ValidityStatus::NOT_OCCUPID;
                }
                start = coordinate;
            } else if (!destination.has_value()) {
                // then destination
                if (board.is_occupied(coordinate)) {
                    return ValidityStatus::OCCUPID;
                }
                destination = coordinate;
            }

            // allow user to reset selection
            reset_if_equal();

            return ValidityStatus::VALID;
        }

        void reset() {
            if (start.has_value()) {
                start = {};
            }

            if (destination.has_value()) {
                destination = {};
            }
        }

        void reset_if_equal() {
            if (ready() && start.value() == destination.value()) {
                start = {};
                destination = {};
            }
        }
    };
} // namespace model