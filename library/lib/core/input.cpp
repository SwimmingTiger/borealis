/*
    Copyright 2021 XITRIX

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <borealis/core/input.hpp>

namespace brls
{

Touch InputManager::computeTouchState(RawTouch currentTouch, Touch lastFrameState)
{
    Touch result = {};
    result.position = currentTouch.position;

    if (currentTouch.pressed)
    {
        if (lastFrameState.phase == TouchPhase::START || lastFrameState.phase == TouchPhase::STAY)
        {
            result.phase = TouchPhase::STAY;
        }
        else
        {
            result.phase = TouchPhase::START;
        }
    }
    else
    {
        if (lastFrameState.phase == TouchPhase::END || lastFrameState.phase == TouchPhase::NONE)
        {
            result.phase = TouchPhase::NONE;
        }
        else
        {
            result.phase = TouchPhase::END;
        }
    }

    return result;
}

} // namespace brls