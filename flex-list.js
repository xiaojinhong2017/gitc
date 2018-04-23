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
import FilterContainer from './Components/filter-container';
import ListContainer from './Components/list-container';
import ResultInformation from './Components/result-information';
/*eslint-enable no-unused-vars*/
import PropTypes from 'prop-types';

module.exports = class FlexList extends React.Component {
    static propTypes = {
        itemsPerPage: PropTypes.number,
        searchConfig: PropTypes.object,
        filtersList: PropTypes.object,
        dataList: PropTypes.array.isRequired,
        texts: PropTypes.object.isRequired
    }

    constructor(props) {
        super(props);
        this._itemsPerPage = this.props.itemsPerPage > 0 ? this.props.itemsPerPage : 10;
        this._searchBoxConfig = this.props.searchConfig;
        this._dropDownFiltersConfig = this.props.filtersList;
        this._dataList = this.props.dataList;
        let texts = this.props.texts;
        this._itemLinkText = texts.itemLinkText;
        this._resultsText = texts.resultsText;
        this._resetText = texts.resetText;
        this._resultNotFoundText = texts.resultNotFoundText;
    }

    _getSubListByFilters() {
        return this._dataList;
    }

    _getSubListByText(rawSearchText) {
        let subList = [],
            filteredList = this._getSubListByFilters(),
            searchText = rawSearchText.trim().toLowerCase();

        if (searchText) {
            filteredList.forEach(function (item) {
                if (
                    (item.name !== undefined && item.name.toLowerCase().indexOf(searchText) !== -1) ||
                    (item.description !== undefined && item.description.toLowerCase().indexOf(searchText) !== -1)
                ) {
                    subList.push(item);
                }
            });
        } else {
            subList = filteredList;
        }

        this.setState({
            renderedDataList: subList
        });
    }

    _handlerFilterInput(selectedValue, filter) {
        this._listContainer.filter(selectedValue, filter);
    }

    _handlerSearchInput(keyword) {
        this._listContainer.search(keyword);
    }

    _handlerListInformationUpdate(listSize) {
        this._resultInformation.updateResultCount(listSize);
    }

    _handlerResetFilters() {
        this._listContainer.reset();
        this._filterContainer.reset();
    }

    render() {
        let filterContainer,
            listfunctions,
            resultInformation,
            listContainer;

        resultInformation =
            <ResultInformation
                resultsText={this._resultsText}
                resetText={this._resetText}
                listSize={this._dataList.length}
                resetFilters={this._handlerResetFilters.bind(this)}
                ref={(resultInformation) => {
                    this._resultInformation = resultInformation;
                }}
            />;

        listfunctions =
            <div className="flex-list__filter-functions">
                <div className="flex-list__reports">
                    <li className="flex-list__report flex-list__historical-report"><a href="">历史报表</a></li>
                    <li className="flex-list__report flex-list__real-time--report"><a href="">实时报表</a></li>
                </div>
                <div className="flex-list__buttons">
                    <li className="flex-list__button flex-list__release">发布</li>
                    <li className="flex-list__button flex-list__unpublish">取消发布</li>
                    <li className="flex-list__button flex-list__delete">删除</li>
                    <li className="flex-list__button flex-list__download">下载</li>
                </div>
            </div>;

        listContainer =
            <ListContainer
                itemsPerPage={this._itemsPerPage}
                dataList={this._dataList}
                itemLinkText={this._itemLinkText}
                resultNotFoundText={this._resultNotFoundText}
                onUpdate={this._handlerListInformationUpdate.bind(this)}
                ref={(listContainer) => {
                    this._listContainer = listContainer;
                }}
            />;

        filterContainer =
            <FilterContainer
                searchBoxConfig={this._searchBoxConfig}
                dropDownFiltersConfig={this._dropDownFiltersConfig}
                onSearch={this._handlerSearchInput.bind(this)}
                onFilter={this._handlerFilterInput.bind(this)}
                resultInformation={resultInformation}
                ref={(filterContainer) => {
                    this._filterContainer = filterContainer;
                }}
            />;

        return (
            <div className="filter-list">
                {listfunctions}
                {filterContainer}
                {listContainer}
            </div>
        );
    }
};
