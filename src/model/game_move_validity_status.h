#pragma once

namespace model {

    enum class GameMoveValidityStatus {
        NOT_OCCUPID, // there is not chess pice that can be selected
        OCCUPID,     // the destination field is occupied
        VALID,       // it is a valid selection
    };
}