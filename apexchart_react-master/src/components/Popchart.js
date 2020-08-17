import React, { Component } from 'react';
import Chart from 'react-apexcharts';

class Popchart extends Component {
    constructor(props) {
        super(props);
        this.state = {
            options: {
                chart: {
                    background: '#ffffff', 
                    foreColor: '#333',
                    toolbar: {
                        show: false
                    },
                },
                xaxis: {
                    categories: [
                        '7/1',
                        '7/2',
                        '7/3',
                        '7/4',
                        '7/5',
                        '7/6',
                        '7/7',
                        '7/8',
                        '7/9',
                        '7/10',
                        '7/11',
                        '7/12',
                        '7/13',
                        '7/14',
                        '7/15',
                        '7/16',
                        '7/17',
                        '7/18',
                        '7/19',
                        '7/20',
                        '7/21',
                    ],
                    labels: {
                        show: true
                    }
                },
                yaxis: {
                    show: false
                },
                plotOptions: {
                    bar: {
                        horizontal: false,
                        distributed: true,
                        startingShape: 'flat',
                        endingShape: 'rounded',
                        columnWidth: '30%',
                        barHeight: '30%',
                        rangeBarOverlap: true,
                    }
                },
                fill: {
                    colors: [
                        '#21d19f',
                        '#21d19f',
                        '#ffba08',
                        '#ffba08',
                        '#d00000',
                        '#21d19f',
                        '#21d19f',
                        '#d00000',
                        '#d00000',
                        '#ffba08',
                        '#ffba08',
                        '#ffba08',
                        '#21d19f',
                        '#21d19f',
                        '#21d19f',
                        '#21d19f',
                        '#21d19f',
                        '#21d19f',
                        '#21d19f',
                        '#21d19f',
                        '#d00000'
                    ]
                },
                legend: {
                    show: false
                },
                dataLabels: {
                    enabled: false
                },
                title: {
                    text: "Utility Zen",
                    align: 'center',
                    margin: 20,
                    offsetY: 20,
                    style: {
                        fontSize: '25px'
                    }
                },
                states: {
                    hover: {
                        filter: {
                            type: 'lighten',
                            value: 0.15,
                        }
                    },
                },
                tooltip: {
                    enabled: false
                }
            },
            series: [
                {
                    name: "Number",
                    data: [
                        1,
                        1,
                        2,
                        2,
                        3,
                        1,
                        1,
                        3,
                        3,
                        2,
                        2,
                        2,
                        1,
                        1,
                        1,
                        1,
                        1,
                        1,
                        1,
                        1,
                        3,
                    ]
                }
            ],
        }
    }


    render() {
        return <Chart
            options={this.state.options}
            series={this.state.series}
            type="bar"
            height="300px"
            width="100%"
        />;
    }
}

export default Popchart;