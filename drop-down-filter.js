/**
 * Copyright (c) 2014-present, San Wei Ju Yuan Tech Ltd. <https://www.3vjuyuan.com>
 * This file is part of swim-reformer
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *
 * For more details:
 * https://www.3vjuyuan.com/licenses.html
 *
 * @author Team Delta <delta@3vjuyuan.com>
 * @author Team Fancy <fancy@3vjuyuan.com>
 */

import React from 'react';  // eslint-disable-line no-unused-vars
import PropTypes from 'prop-types';

module.exports = class DropDownFilter extends React.PureComponent {
    static propTypes = {
        filterLabel: PropTypes.string,
        onChange: PropTypes.func.isRequired,
        filterName: PropTypes.string,
        optionsList: PropTypes.object.isRequired
    }

    constructor(props) {
        super(props);

        this._initialState = {
            currentOptionText: this.props.filterLabel,
            currentOptionValue: null,
            isSelected: false
        };

        this.state = this._initialState;
    }

    _handlerClick(option) {
        let element = option.target,
            isOption = element.hasAttribute('data-value'),
            selectedValue = element.getAttribute('data-value');

        this.setState({
            currentOptionText: element.textContent,
            currentOptionValue: isOption ? selectedValue : null,
            isSelected: isOption
        });

        this.props.onChange(isOption ? selectedValue : null, this.props.filterName);
    }

    reset() {
        this.setState(this._initialState);
    }

    render() {
        const {filterName, filterLabel, optionsList, ...pros} = this.props; // eslint-disable-line no-unused-vars
        const {currentOptionText, currentOptionValue, isSelected} = this.state;

        let options = [<li key={filterName + '-'} className="dropdown-item placeholder"
                           onClick={this._handlerClick.bind(this)}>{filterLabel}</li>];

        for (let key in optionsList) {
            options.push(
                <li key={filterName + '-' + key} data-value={key} className="dropdown-item"
                    onClick={this._handlerClick.bind(this)}>{optionsList[key]}</li>
            );
        }

        return (
            <div className="filter-list__filter">
                <div className="dropdown col-12">
                    <button className="col-12 filter-list__filter-button btn dropdown-toggle"
                            type="button" data-toggle="dropdown" aria-haspopup="true"
                            aria-expanded="false"><span value={currentOptionValue}>{currentOptionText}</span></button>
                    <ul className={"dropdown-menu filter-list__dropdown" + (isSelected ? " selected" : "")}
                        aria-labelledby="filter-list__filter-button">
                        {options}
                    </ul>
                </div>
            </div>
        );
    }
};
