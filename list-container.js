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
import DataList from './data-list';
import Pagination from './pagination';
/*eslint-enable no-unused-vars*/
import PropTypes from 'prop-types';

module.exports = class ListContainer extends React.Component {
    static propTypes = {
        dataList: PropTypes.array.isRequired,
        itemsPerPage: PropTypes.number.isRequired,
        itemLinkText: PropTypes.string,
        resultNotFoundText: PropTypes.string.isRequired,
        onUpdate: PropTypes.func.isRequired
    }

    constructor(props) {
        super(props);
        this._dataList = this.props.dataList;
        this._itemsPerPage = this.props.itemsPerPage;
        this._itemLinkText = this.props.itemLinkText;
        this._resultNotFoundText = this.props.resultNotFoundText;

        this._initialState = {
            renderedPerPage: this._itemsPerPage,
            pageIndex: "",
            currentPage: 0,
            renderedDataList: this._dataList,
            searchText: "",
            filters: {}
        };

        this.state = this._initialState;
    }

    _getFilteredSubList(filters = null) {
        if (filters === null) {
            filters = this.state.filters;
        }

        if (Object.keys(filters).length === 0 && filters.constructor === Object) {
            return this._dataList;
        }

        let filteredList = [];
        this._dataList.forEach(function (item) {
            for (let key in filters) {
                if (item.options[key][filters[key]] === undefined) {
                    return;
                }
            }

            filteredList.push(item);
        });

        return filteredList;
    }

    filter(selectedValue, filter) {
        let filters = this.state.filters;

        if (selectedValue !== null) {
            filters[filter] = selectedValue;
        } else {
            delete filters[filter];
        }

        this.search(this.state.searchText, filters);
    }

    search(rawSearchText, filters = null) {
        let subList = [],
            filteredList = this._getFilteredSubList(filters),
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
            renderedPerPage: this._itemsPerPage,
            currentPage: 0,
            renderedDataList: subList,
            searchText: searchText,
            filters: filters === null ? this.state.filters : filters
        });

        this.props.onUpdate(subList.length);
    }

    reset() {
        this._initialState.filters = {};
        this.setState(this._initialState);
        this.props.onUpdate(this._dataList.length);
    }

    _handlePageClick(e) {
        this.setState({
            currentPage: e.selected
        });
    }

    _quantityChange(e) {
        this.setState({
            renderedPerPage: e.target.value,
        });
    }

    _pageIndexChange(e) {
        this.setState({
            pageIndex: e.target.value,
        });
    }

    _pageIndexKeyPress(event) {
        let code = event.which || event.keyCode;
        code === 13 && this._pageIndexClick();
    }

    _pageIndexClick() {
        this.setState({
            currentPage: Number(this.state.pageIndex - 1)
        });
    }

    render() {
        const {currentPage, renderedDataList, renderedPerPage} = this.state;
        let listContent,
            pagination;

        listContent =
            <DataList
                dataList={renderedDataList.slice(currentPage * renderedPerPage, (currentPage + 1) * renderedPerPage)}
                itemLinkText={this._itemLinkText}
                resultNotFoundText={this._resultNotFoundText}
            />;

        pagination =
            <div className="list__pagination">
                <div className="pagination__container">
                    <div className="show__page--number float__left">
                        <span>显示</span>
                        <select onChange={this._quantityChange.bind(this)} value={renderedPerPage}>
                            <option value="10">10</option>
                            <option value="15">15</option>
                            <option value="20">20</option>
                            <option value="25">25</option>
                            <option value="30">30</option>
                        </select>
                    </div>
                    <Pagination
                        totalPage={Math.ceil(renderedDataList.length / renderedPerPage)}
                        viewPage={currentPage}
                        currentPage={currentPage}
                        handlePageClick={this._handlePageClick.bind(this)}
                    />
                    <div className="change__page--number float__left">
                        <span>跳转到</span>
                        <input type="number" className="list__page--index" onChange={this._pageIndexChange.bind(this)}
                               onKeyPress={this._pageIndexKeyPress.bind(this)}/>
                        <span>页</span>
                        <input type="button" className="change__page--button" onClick={this._pageIndexClick.bind(this)}
                               value="确定"/>
                    </div>
                </div>
            </div>;

        return (
            <div>
                {listContent}
                {pagination}
            </div>
        );
    }
};
