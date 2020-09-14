import React from 'react';
import styled from 'styled-components'

const Bigpic = styled.div`
    display: flex;
    align-items: center;
`
const Container = styled.div`
    display: flex;
    height: 80px;
    width: 54.5rem;
    align-items: center;
    margin: auto;
    padding: 1rem 0;
    border-bottom: 1px solid rgba(190,190,190,0.22);
    cursor: pointer;
    transition: all ease-in-out 300ms;

    &:hover {
        /* box-shadow: 0px 10px 8px -8px rgba(138, 153, 192, 0.6); */
        background-color: #F8F8F8;
    }
`
const Property = styled.div`
    display: flex;
    align-items: center;
    padding-left: 40px;
`
const Category = styled.div`
    width: 15rem;
    height: 18px;
    display: flex;
    align-items: center;
`
const Category_image = styled.img`
    width: 48px;
    height: 48px;
`
const CategoryText = styled.div`
    display: flex;
    flex-direction: column;
    margin-left: 1rem;
    width: 58px;
    height: 18px;
    font-family: SlatePro-Bk;
    font-size: 18px;
    font-weight: normal;
    font-stretch: normal;
    font-style: normal;
    line-height: 1;
    letter-spacing: normal;
    color: #ffba08;
`
const CategoryText2 = styled.div`
    display: flex;
    flex-direction: column;
    margin-left: 0.5rem;
    width: 200px;
    height: 18px;
    font-family: SlatePro-Medium;
    font-size: 18px;
    font-weight: 500;
    font-stretch: normal;
    font-style: normal;
    line-height: 1;
    letter-spacing: normal;
    color: #ffba08;
`
const StreetText = styled.div`
    display: flex;
    flex-direction: column;
    margin-left: 1rem;
`
const Message = styled.div`
    display: flex;
    align-items: center;
    width: 14rem;
    height: 18px;
    font-family: SlatePro-Bk;
    font-size: 18px;
    font-weight: normal;
    font-stretch: normal;
    font-style: normal;
    line-height: 1;
    letter-spacing: normal;
    color: #1a1e42;
`
const Street = styled.div`
    display: flex;
    align-items: center;
    width: 90px;
    height: 18px;
    font-family: SlatePro;
    font-size: 18px;
    font-weight: 900;
    font-stretch: normal;
    font-style: normal;
    line-height: 1;
    letter-spacing: normal;
    color: #1a1e42;
`
const MoveInDate = styled(Text)`
    width: 15%;
`
const Rent = styled(Text)`
    width: 10%;
`
const DepositWrapper = styled.div`
    width: 15%;
`
const Status = styled.div`
    display: flex;
    align-items: center;
`
const StatusIndicator = styled.div`
    width: 15px;
    height: 15px;
    border-radius: 10px;
    background-color: ${props => props.color};
    margin-left: 1rem;
    position: absolute;
    right: 7rem;
`

const AlertsComponents = ({ alert }) => {
  const { property, moveInDate, rent, deposit, status } = alert;

  return (
    <Bigpic>
      <Container>
        <Property>
          <Category_image src={`${alert.logo}`} alt={alert.category} />
        </Property>
        <Category>
          <CategoryText>{alert.category}</CategoryText>
          <CategoryText2>{alert.status}</CategoryText2>
        </Category>
        <StreetText>
          <Message>{alert.detail}</Message>
          <Street>{alert.address}</Street>
        </StreetText>
        <Property>{alert.time}</Property>
      </Container>
    </Bigpic>
  )
}
  // <div className='flex bg-white sm:shadow-md m-4 p-5'>
  //   <div>
  //     <img src={`${alert.logo}`} alt={alert.category} />
  //   </div>
  //   <div className='flex flex-col ml-4'>
  //     <span className='text-xl'>{alert.category}</span>
  //   </div>
  // </div>


export default AlertsComponents;