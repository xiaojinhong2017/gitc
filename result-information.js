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

module.exports = class ResultInformation extends React.PureComponent {
    static propTypes = {
        resultsText: PropTypes.string.isRequired,
        resetText: PropTypes.string.isRequired,
        listSize: PropTypes.number.isRequired,
        resetFilters: PropTypes.func.isRequired
    }

    constructor(props) {
        super(props);
        this._resultsText = this.props.resultsText;
        this._resetText = this.props.resetText;

        this.state = {
            listSize: this.props.listSize
        };
    }

    updateResultCount(listSize) {
        this.setState({
            listSize: listSize
        });
    }

    render() {
        return (
            <div className="filter-information">
                <a className="reset filter-reset" href="#" onClick={this.props.resetFilters}>{this._resetText}</a>
                <div className="text filter-result">{this._resultsText}
                    <span>{this.state.listSize}</span>
                </div>
            </div>
        );
    }
};
