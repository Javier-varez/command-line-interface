/*
 * Command-line Processor
 * Copyright (C) 2018 AllThingsEmbedded
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "command.h"

Command::Command(command_t fcn, const std::string &name, CommandProcessor *processor, void *implicitArg): 
    fcn(fcn),
    name(name),
    processor(processor),
    implicitArg(implicitArg)
{

}

void Command::execute() {
    if (fcn != nullptr) {
        fcn(processor, implicitArg);
    } 
}

int Command::match(const std::string &commandName) {
    if (name.compare(commandName) == 0)
        return 1;
    return 0;
}
