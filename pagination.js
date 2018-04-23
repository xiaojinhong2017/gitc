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
import ReactPaginate from 'react-paginate';
/*eslint-enable no-unused-vars*/
import PropTypes from 'prop-types';

module.exports = class Pagination extends React.PureComponent {
    static propTypes = {
        totalPage: PropTypes.number.isRequired,
        viewPage: PropTypes.number.isRequired,
        currentPage: PropTypes.number.isRequired,
        handlePageClick: PropTypes.func.isRequired
    }

    constructor(props) {
        super(props);
    }

    render() {
        const {totalPage, viewPage, currentPage, handlePageClick, ...pros} = this.props;  // eslint-disable-line no-unused-vars

        return (
            <div className="filter-list__pagination">
                <nav aria-label="Page navigation" className="bt-pagination-nav">

                    <ReactPaginate  pageCount={totalPage}
                                    pageRangeDisplayed={viewPage}
                                    marginPagesDisplayed={1}
                                    onPageChange={handlePageClick}
                                    forcePage={currentPage}
                                    previousLabel={<span aria-hidden="true">上一页</span>}
                                    nextLabel={<span aria-hidden="true">下一页</span>}
                                    breakLabel={<span className="fill">...</span>}
                                    breakClassName={"break-me"}
                                    containerClassName = {"pagination pagination-sm"}
                                    pageLinkClassName = {"page-link"}
                                    activeClassName = {"active"}
                                    previousLinkClassName = {"arrow page-link"}
                                    nextLinkClassName = {"arrow page-link"}
                                    disabledClassName = {"disabled-arrow"}
                    />
                </nav>
            </div>
        );
    }
};
