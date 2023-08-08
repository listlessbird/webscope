import { ReactComponent as Logo } from "../assets/rotate.svg"
export default function Header() {
  return (
    <div
      className="max-w-[120rem]
    text-center
    lg:text-left pl-4
    "
    >
      <h1
        className="text-[3rem] font-bold uppercase m-auto  pt-7 font-sourceCodePro
      "
      >
        Webscope
        <span className="version text-[1.25rem] font-normal">0.0.1</span>
      </h1>
      <p className="text-lg font-normal font-Poppins">
        A project by ECE S6 Batch 2020-2024.
      </p>
      <div className="w-[5rem] h-[5rem] ml-auto mr-auto mt-4 bg-[#232323] rounded-full flex c-br justify-center border-[1px] border-solid border-white">
        <Logo className="self-center" />
      </div>
    </div>
  )
}
