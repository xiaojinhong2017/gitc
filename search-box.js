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

module.exports = class SearchBox extends React.PureComponent {
    static propTypes = {
        label: PropTypes.string,
        placeholder: PropTypes.string,
        className: PropTypes.string,
        onSearch: PropTypes.func.isRequired
    }

    constructor(props) {
        super(props);

        this.state = {
            keyword: ""
        };
    }

    _handlerSearchInput(searchElement) {
        let searchWord = searchElement.target.value;
        this.setState({
            keyword: serchWord
        });
        this.props.onSearch(searchWord);
    }

    _handlerSearchIcon(searchWord) {
        this.setState({
            keyword: searchWord
        });
        this.props.onSearch(searchWord);
    }

    reset() {
        this.setState({
            keyword: ""
        });
    }

    render() {
        const {label, placeholder, className, ...pros} = this.props;  // eslint-disable-line no-unused-vars
        let searchClassName = "react-list__search" + (className ? className : "");
        // labelElement;

        // if (label) {
        // labelElement = <label className="col-3 col-sm-2 col-md-3">{label}</label>;
        // }

        return (
            <div className="filter-list__search-container">
                <div className={searchClassName}>
                    {/*{labelElement}*/}
                    <input type="text"
                           className="search-field"
                           placeholder={placeholder}
                           value={this.state.keyword}
                           onChange={this._handlerSearchInput.bind(this)}
                    />
                    <span className="search-field--icon" onClick={this._handlerSearchIcon.bind(this, this.state.keyword)}>

                    </span>
                </div>
            </div>
        );
    }
};
