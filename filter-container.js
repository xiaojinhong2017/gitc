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

/*eslint-disable no-unused-vars*/
import React from 'react';
import DropDownFilter from './drop-down-filter';
import SearchBox from './search-box';
/*eslint-enable no-unused-vars*/
import PropTypes from 'prop-types';

module.exports = class FilterContainer extends React.Component {
    static propTypes = {
        searchBoxConfig: PropTypes.object,
        dropDownFiltersConfig: PropTypes.object,
        onSearch: PropTypes.func,
        onFilter: PropTypes.func,
        resultInformation: PropTypes.element
    }

    constructor(props) {
        super(props);
        this._searchBoxConfig = this.props.searchBoxConfig;
        this._dropDownFiltersConfig = this.props.dropDownFiltersConfig;
        this._dropDownFilters = {};
    }

    reset() {
        this._searchBox.reset();
        for (let filter in this._dropDownFilters) {
            this._dropDownFilters[filter].reset();
        }
    }

    render() {
        let searchBox,
            filterList = [];

        if (this._searchBoxConfig) {
            searchBox =
                <SearchBox
                    label={this._searchBoxConfig.label}
                    placeholder={this._searchBoxConfig.placeholder}
                    className={this._searchBoxConfig.className}
                    onSearch={this.props.onSearch}
                    ref={(searchBox) => {
                        this._searchBox = searchBox;
                    }}
                />;
        }

        for (let key in this._dropDownFiltersConfig) {
            let filter =
                <DropDownFilter
                    key={'filter-' + key}
                    filterName={key}
                    filterLabel={this._dropDownFiltersConfig[key]['label']}
                    optionsList={this._dropDownFiltersConfig[key]['options']}
                    onChange={this.props.onFilter}
                    ref={(dropDownFilter) => {
                        this._dropDownFilters[key] = dropDownFilter;
                    }}
                />;
            filterList.push(filter);
        }

        return (
            <div className="flex-list__filter-list">
                <div className="flex-list__filter-container">
                    <div className="flex-list__filter-row row">
                        {filterList}
                        {searchBox}
                        {this.props.resultInformation}
                    </div>
                </div>
            </div>
        );
    }
};
